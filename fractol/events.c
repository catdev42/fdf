/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/07 22:13:35 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./include/fdf.h"
#include "./include/fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal); // TODO
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5;
	else if (keysym == XK_p)
		fractal->iter_definition += 10;
	else if (keysym == XK_m)
		fractal->iter_definition -= 10;
	fractal_render(fractal);
	return (0);
}

// int
//        mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
//         mouse_hook(int button,int x,int y,void *param);
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	// up
	if (button == Button5)
	{
		fractal->zoom *= 1.1;
		// 	fractal->shift_x -= ((double)x - (WIDTH / 2)) / 800 * (fractal->zoom
		// * 2);
		// 	fractal->shift_y += ((double)y - (HEIGHT / 2)) / 800
		// *(fractal->zoom * 2);
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.9;
		// fractal->shift_x -= ((double)x - (WIDTH / 2)) / 800 * (fractal->zoom
		// * 2);
		// fractal->shift_y += ((double)y - (HEIGHT / 2)) / 800
		// *(fractal->zoom * 2);
	}
	printf("x = %i, y = %i \n", x, y);
	printf("fractal->shift_x = %f, fractal->shift_y = %f \n", fractal->shift_x,
		fractal->shift_y);
	// refresh
	fractal_render(fractal);
	return (0);
}
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*track the mouse to change julia dynamically*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map((double)x, -2, 2, 0, WIDTH - 1) * fractal->zoom)
			+ (fractal->shift_x) * fractal->zoom;
		fractal->julia_y = (map((double)y, 2, -2, 0, HEIGHT - 1)
				* fractal->zoom) + (fractal->shift_x) * fractal->zoom;

		fractal_render(fractal);
	}
	return (0);
}