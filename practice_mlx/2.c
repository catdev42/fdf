/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:24:29 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/01 20:30:01 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

int	main(void)
{
	void *mlx_connection;
	void *window1;
	void *window2;

	mlx_connection = mlx_init();
	window1 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "my window");
	if (NULL == window1)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, window1);
}