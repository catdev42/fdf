/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/03 19:43:31 by myakoven         ###   ########.fr       */
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
