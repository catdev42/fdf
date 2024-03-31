#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800
/*
FRACTAL ID
~MLX stuff
~Image
~Hook value
*/
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

typedef struct s_fractal
{
	char	*name;
	void *mlx_connection; // mlx_init()
	void *mlx_window;     // mlx_new_window
	// Image
	t_image	img;
	// Hook member variable TODO

}			t_fractal;

void		fractal_init(t_fractal *fractal);
int			fractol_clean(t_fractal *fractal, int err);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

#endif