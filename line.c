/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:46:12 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/18 22:28:22 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

typedef struct s_bresenham
{
    double x2;
    double y2;
    double x1;
    double y1;
    double deviation;
    int sign_y;
    int sign_x;
}		t_bresenham;

void	draw_line(double x2, double y2, t_fdf *fdf, int current_i)
{
	int x;
	int y;
	int dx;
	int dy;
	int deviation;

	x = fdf->points.iso_x[current_i];
	y = fdf->points.iso_y[current_i];

	dx = abs(fdf->points.iso_x[current_i + 1] - fdf->points.iso_x[current_i]);
	dy = abs(fdf->points.iso_y[current_i + 1] - fdf->points.iso_y[current_i]);
	// deviation=

	while (x != x2 || y != y2)
	{
		record_pixel(x, y);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
		// fdf->points.iso_x(current_i);
		//     fdf->points.iso_y = 0;
	}
}

/*https://editor.p5js.org/strangecatdev/sketches/JNxfF4hO7*/
