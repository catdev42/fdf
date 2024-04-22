#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # define ERROR_MESSAGE "Please enter \n\t\"./fdf mapname\" or \n\t\"./fdf mapname <width> <height>\"\n"
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_bres
{
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	uint32_t	color;
}				t_bres;
/// translate
typedef struct s_points
{
	double		*x;
	double		*y;
	double		*z;
	uint32_t	*color;
	double		*iso_x;
	double		*iso_y;
	int			*map_x;
	int			*map_y;
	// int			*map_z;
	// TRANSLATIONS
	double		orig_min;
	double		orig_max;
	double		target_min;
	double		target_max;

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
 * the map contains everything
 * all user manipulations
 * points
 * image
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
	t_bres		bres;

	// OPERATIONS on visuals
	double		zoom;
	double		shift_x;
	double		shift_y;
	double		angle;
}				t_fdf;

/******main.c********/
int				fdf_clean(t_fdf *fdf, int err);
void			free_split(char **arr);

/******events.c********/
int				close_handler(t_fdf *fdf);
int				mouse_handler(int button, int x, int y, t_fdf *fdf);
int				key_handler(int keysym, t_fdf *fdf);
void			reset(t_fdf *fdf);

/******init.c********/
int				fdf_init(t_fdf *fdf);

/******parse.c********/
int				parse_data(int fd, t_fdf *fdf);
int				calculate_translation(t_fdf *fdf, t_points *points);

/******math_utils.c********/
double			map(double unscaled_num, double original_min,
					double original_max, double target_min, double target_max);
int				ahextoi(const char *nptr);

/******render.c********/
void			render_lines(t_bres *bres, t_fdf *fdf);

// int	fdf_render(t_fdf *fdf);    // TODO
// int	render_pixels(t_fdf *fdf); // TODO
#endif