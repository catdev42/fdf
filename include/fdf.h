#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

// #include <fildes.h>

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	// should iso be mapped to the screen? no, transform later
	int			iso_x;
	int			iso_y;
}				t_point;

typedef struct s_image
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_image;

/*
 * the map contains all main manipulations
 *to fix the points to the canvas
 */
typedef struct s_map
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		img;
	double		zoom;
	double		shift_x;
	double		shift_y;
	double		angle;
}				t_map;

# define ERROR_MESSAGE "Please enter \n\t\"./fdf mapname\" or \n\t\"./fdf mapname <width> <height>\"\n"

#endif