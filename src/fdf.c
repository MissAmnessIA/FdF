#include "../inc/fdf.h"

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

// void	color_screen(t_mlx_data *data, int color)
// {
// 	for (int y = 0; y < SIDE_LEN; ++y)
// 	{
// 		for (int x = 0; x < SIDE_LEN; ++x)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, color);
// 		}
// 	}
// }

void	my_pixel_put(t_mlx_data *img, int x, int y, int color)
{
	int offset;

	offset = (img->line_len * y) + (x * (img->img_bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}
void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < SIDE_LEN, ++y)
	{
		for(int x = 0; x < SIDE_LEN, ++x)
		{
			my_pixel_put(&data->img,
						x,
						y,
						color);
		}
	}
}
int	f(int keysym, t_mlx_data *data)
{
	if (keysym == XK_r)
		color_screen(data, encode_rgb(255, 0, 0));
	else if (keysym == XK_g)
		color_screen(data, encode_rgb(0, 0xff, 0));
	else if (keysym == XK_b)
		color_screen(data, encode_rgb(0, 0, 0xff));
	else if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		//free(data);
		exit (1);
	}
	mlx_put_image_to_window(data->mlx,data->win,data->img.img_ptr);
	return (0);
}

/*int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx,data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n",keysym);
	return (0);
}*/
int main (void)
{
	t_mlx_data data;

	data.mlx = mlx_init();
	data.win= mlx_new_window(data.mlx, SIDE_LEN, SIDE_LEN, "Ventana kiut");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx, SIDE_LEN, SIDE_LEN);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, 
												&data.img.bits_per_pixel,
												&data.img.line_len,
												&data.img.endian);
	mlx_key_hook(data.win, f, &data);

	mlx_loop(data.mlx);
	return(0);
}