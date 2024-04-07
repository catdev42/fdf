/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:26:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/07 22:36:25 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/* 
    Reset to original isometric projection.
    Original view.
*/
void	reset(t_map *fdf)
{
	fdf->angle = sqrt(3) / 3;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->zoom = 0;

    render_pixels(fdf); //TODO

}
