/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:24:29 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/01 21:36:14 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx_data
{
	void	*mlx_connection;
	void	*mlx_window;
	int		color;
}			t_data;

int	main(void)
{
	t_data	data;

	data.mlx_connection = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx_connection, 400, 400,
			"hook tests");
    data.color = 0xFF0000;
    
}
