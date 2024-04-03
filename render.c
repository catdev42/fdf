/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/03 20:26:43 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"

/*
800 x 800 >>>> -2 x 2

	MANDELBROT
	x = x^2 + c;
	z is initially (0,0)
	c is the actual point
	(thoughts so each point recursively creates other points?)

*/
void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// 1st iteration
	z.x = 0.0;
	z.y = 0.0;
	// starting pixel coordinated x & y scaled from canvas size
	c.x = map((double)x, -2, 2, 0, WIDTH - 1) + fractal->shift_x;
	c.y = map((double)y, 2, -2, 0, HEIGHT - 1) + fractal->shift_y;
	// how many times do we want to iterate x^2 + c
	// to check if the point escaped
	while (i < fractal->iter_definition) // TODO
	{
		// actual z^2 +c
		// z = z^2 + c
		z = sum_complex(square_complex(z), c);
		// if the value is escaped
		// aka if hypotenuse > 2, I assume that the point has escaped
		// square_root(a^2 + b^2)
		if (((z.x * z.x) + (z.y * z.y)) > fractal->escape_value)
		{
			// color is direct relationship between number of iterations and color value
			color = map(i, 0x000000, 0xFFFFFF, 0, fractal->iter_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	// if we are within the mandelbrot set, put one color pixel
	my_pixel_put(x, y, &fractal->img, 0xff0000);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
