/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/06 01:28:16 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (argc == 4)
		{
			fractal.julia_x = atodbl(argv[2], &fractal);
			fractal.julia_y = atodbl(argv[3], &fractal);
		}
		// big function
		// 1)
		fractal_init(&fractal);
		// //2)
		fractal_render(&fractal);
		// //3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
}

int	fractol_clean(t_fractal *fractal, int err)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	if (err == 1)
	{
		perror("Problems with malloc");
		return (1);
	}
	if (err == 2)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 800)
// 	{
// 		printf("%d -> %f\n", i, scale((double)i, -2, +2, 0, 799));
// 		i++;
// 	}
// }
