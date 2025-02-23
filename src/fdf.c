#include "../inc/fdf.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n",keysym);
	return (0);
}
int main (void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr= mlx_new_window(data.mlx_ptr, 500, 500, "Ventana kiut");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	mlx_key_hook(data.win_ptr, handle_input, &data);

	mlx_loop(data.mlx_ptr);
}