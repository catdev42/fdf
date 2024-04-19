/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:00:13 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/19 15:57:36 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		fdf_render(t_fdf *fdf);
int		my_put_pixel(t_fdf *fdf);
void	make_line(t_line *line, t_fdf *fdf);

/*
1. Call render function
2. Fill bres struct 2 points at a time, both to (x+1, y) && (x, y+1)
	* map initial iso points into bres using MAP function
	* draw a line, filling it in pixel by pixel
	* go to next points



*/

int	fdf_render(t_fdf *fdf)
{
	return (0);
}

int	my_put_pixel(t_fdf *fdf)
{
}

void	make_line(t_line *line, t_fdf *fdf)
{
	int e2;
	int err;
	int sx;
	int sy;

	// line->x = fdf->points.iso_x[current_i];
	// line->y = fdf->points.iso_y[current_i];
	// line->dx = abs(fdf->points.iso_x[current_i + 1]
			- fdf->points.iso_x[current_i]);
			// line->dy = abs(fdf->points.iso_y[current_i + 1]
			- fdf->points.iso_y[current_i]);
			err = line->dx - line->dy;
			while (line->x != line->x2 || y != y2)
			{
				record_pixel(x, y);
				e2 = 2 * err;
				if (e2 > -dy)
				{
					err -= dy;
					x += line.sx;
				}
				if (e2 < dx)
				{
					err += dx;
					y += sy;
				}
			}
}
