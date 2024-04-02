/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/01 23:11:07 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"
#include <time.h>

// #include <mathcalls.h>

int	main(void)
{
	void *mlx_connection;
	void *mlx_window;
	int y;
	int x;
	double angle;
	int color;
	
	srand(time(NULL));
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Pollack");
	// CIRCLE
	// angle = 0;
	// while (angle < 360)
	// {
	// 	x = (int)(WIDTH / 2 + 300 * -cos(angle));
	// 	y = (int)(HEIGHT / 2 + 300 * sin(angle));

	// 	mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0xFF0000);
	// 	angle += 0.02;
	// }
	// color = mlx_int_to_rgb();

	// SQUARE
	y = HEIGHT * 0.1;
	while (y < HEIGHT - HEIGHT * 0.1)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH - WIDTH * 0.1)
		{
			// mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0x1000000);
			mlx_pixel_put(mlx_connection, mlx_window, x, y, 0x9900FF55);

			x+=2;
		}
		y++;
	}
	mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.8, HEIGHT * 0.95,
		rand() % 0x1000000, "my pollock");
	mlx_loop(mlx_connection);
}