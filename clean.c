/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 20:09:49 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"

int	fractol_clean(t_fractal *fractal, int err)
{
	if (fractal->mlx_connection)
		free(fractal->mlx_connection);
	if (fractal->mlx_window)
		free(fractal->mlx_window);
    if (err == 1)
    {
        perror("Problems with malloc");
        return(1);
    }
    return (0);
}