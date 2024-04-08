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

# define WIDTH 800
# define HEIGHT 800
# define ERROR_MESSAGE "Please enter \n\t\"./fdf mapname\" or \n\t\"./fdf mapname <width> <height>\"\n"

typedef struct s_points
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
	double		iso_x;
	double		iso_y;
}				t_points;

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
 *to fix the points to the canvas as well as points and
 */
typedef struct s_fdf
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		img;

	// MAP INFO
	int			x_len;
	int			y_len;
	int			total_points;
	int			z_min;
	int			z_max;
	int			z_range;
	t_points	points;

	// OPERATIONS
	double		zoom;
	double		shift_x;
	double		shift_y;
	double		angle;
}				t_fdf;

/**********FUN***********/

/******main.c********/
int				fdf_clean(t_fdf *fdf, int err);

/******events.c********/
int				close_handler(t_fdf *fdf);
int				mouse_handler(int button, int x, int y, t_fdf *fdf);
int				key_handler(int keysym, t_fdf *fdf);

/******init.c********/
int				fdf_init(t_fdf *fdf);
void			reset(t_fdf *fdf);

/******parse.c********/
int				parse_data(char *data, t_fdf fdf);

/******math_utils.c********/
double			map(double unscaled_num, double new_min, double new_max,
					double old_min, double old_max);

#endif