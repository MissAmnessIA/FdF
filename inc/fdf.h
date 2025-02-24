#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/inc/libft.h"
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define SIDE_LEN 800
typedef unsigned char	byte;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_mlx_data
{
	void		*mlx;
	void		*win;
	//int			color;
	t_img		img;
}				t_mlx_data;

#endif