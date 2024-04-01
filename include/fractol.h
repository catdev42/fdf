#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define BROWN 0xA52A2A
# define PINK 0xFFC0CB
# define GRAY 0x808080

/* STRUCT COMPLEX*/

typedef struct s_complex
{
	// real
	double	x;
	// imaginary
	double	y;
}			t_complex;

/*
 * Image is a pixel buffer
 * value from mlx_get_data_addr()
 */
typedef struct s_image
{
	void *img_ptr;    // pointer to image struct
	char *pixels_ptr; // points to the acttual pixels
	int bpp;          // pits per pixel 32
	int line_len;     // for pixel_put function
	int		endian;
}			t_image;

/*
 * FRACTAL ID
 * ~MLX stuff
 * ~Image
 * ~Hook value
 */
typedef struct s_fractal
{
	char	*name;
	void *mlx_connection; // mlx_init()
	void *mlx_window;     // mlx_new_window
	// Image
	t_image	img;
	// Hook member variable TODO
	double escape_value; // hypotenuse
	int iter_definition; // number of iterations
		// - tied with quality and render speed
}			t_fractal;

/*INIT*/
void		fractal_init(t_fractal *fractal);

/*CLEAN*/
int			fractol_clean(t_fractal *fractal, int err);

/*RENDER*/
void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

/*MATH UTILS*/
double		map(double unscaled_num, double n_min, double n_max, double o_min,
				double o_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
#endif