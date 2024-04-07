#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	int			iso_x;
	int			iso_y;
}				t_point;

#endif