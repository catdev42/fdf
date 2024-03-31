/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 21:13:08 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"
#include <stdio.h>

double	scale(double unscaled_num, double n_min, double n_max, double o_min,
		double o_max)
{
	double	nnum;

	nnum = (n_max - n_min) * (unscaled_num - o_min) / (o_max - o_min) + n_min;
	return (nnum);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
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
