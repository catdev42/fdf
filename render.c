/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:00:13 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/20 23:13:15 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		fdf_render(t_fdf *fdf);
int		my_put_pixel(int x, int y, t_image *img, int color);
void	make_line(t_line *line, t_fdf *fdf);

/*
1. Call render function
2. Fill bres struct 2 points at a time, both to (x+1, y) && (x, y+1)
	* map initial iso points into bres using MAP function
	* draw a line, filling it in pixel by pixel
	* go to next points



*/

// put values into bres line
int	fdf_render(t_fdf *fdf)
{
	int		j;
	int		k;
	int		ind;
	t_bres	*bres;

	bres = &fdf->bres;
	j = 0;
	ind = 0;
	while (j < fdf->y_len)
	{
		k = 0;
		while (k < fdf->x_len - 1)
		{
			make_line(&fdf->bres, fdf);
			ind++;
			k++;
		}
		j++;
	}
	return (0);
}

int	my_put_pixel(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	init_bres(t_bres *bres)
{
	bres->dx = abs(bres->x2 - bres->x);
	bres->dy = abs(bres->y2 - bres->y);
	if (bres->y2 > bres->y)
		bres->sy = 1;
	else
		bres->sy = -1;
	if (bres->x2 > bres->x)
		bres->sx = 1;
	else
		bres->sx = -1;
}

void	make_line(t_bres *bres, t_fdf *fdf)
{
	int	e2;
	int	err;
	int	sx;
	int	sy;
	int	i;

	while (i < (fdf->x_len * fdf->y_len) - 1)
	{
		bres->x = (int)floor(fdf->points.map_x[i]);
		bres->y = (int)floor(fdf->points.map_y[i]);
		if (fdf->points.x[i] < fdf->x_len - 2)
		{
			bres->x2 = (int)floor(fdf->points.map_x[i + 1]);
			bres->y2 = (int)floor(fdf->points.map_y[i + 1]);
			init_bres(bres);
		}

		if (fdf->points.y[i] < fdf->y_len - 2)
		{
			bres->x2 = (int)floor(fdf->points.map_x[i + 1]);
			bres->y2 = (int)floor(fdf->points.map_y[i + fdf->x_len]);
		}
		err = bres->dx - bres->dy;
		while (bres->x != bres->x2 || y != y2)
		{
			if (pixel_within_canvas)
				record_pixel(x, y);
			e2 = 2 * err;
			if (e2 > -dy)
			{
				err -= dy;
				x += bres.sx;
			}
			if (e2 < dx)
			{
				err += dx;
				y += sy;
			}
		}
		// CONNECT TO NEXT Y
		if (fdf->points.y[i] < fdf->y_len - 2)
		{
			bres->x2 = fdf->points.map_x[i + 1];
			bres->y2 = fdf->points.map_y[i + fdf->x_len];
		}
		// line->x = fdf->points.iso_x[current_i];
		// line->y = fdf->points.iso_y[current_i];
		// line->dx = abs(fdf->points.iso_x[current_i + 1]
		// - fdf->points.iso_x[current_i]);
		// line->dy = abs(fdf->points.iso_y[current_i + 1]
		// - fdf->points.iso_y[current_i]);
		// START
		// err = line->dx - line->dy;
		// while (line->x != line->x2 || y != y2)
		// {
		// 	if (pixel_within_canvas)
		// 		record_pixel(x, y);
		// 	e2 = 2 * err;
		// 	if (e2 > -dy)
		// 	{
		// 		err -= dy;
		// 		x += line.sx;
		// 	}
		// 	if (e2 < dx)
		// 	{
		// 		err += dx;
		// 		y += sy;
		// 	}
		// }
		i++;
	}
}

// was in render

// TODO TODO TODO TODO TODO
// INIT BRESENHAMS VALUES
// init_brez_accross(fdf->points.iso_x[ind], fdf->points.iso_x[ind
// 	+ 1], fdf->points.iso_y[ind], fdf->points.iso_y[ind]);
// TODO
// bres->x = map(fdf->points.iso_x[ind], 0, fdf->x_len - 1, tarmin,
// 		tarmin * 7);
// bres->x2 = map(fdf->points.iso_x[ind + 1], 0, fdf->x_len - 1, 0,
// 		WIDTH);
// bres->y = map(fdf->points.iso_y[ind], 0, fdf->y_len - 1, 0,
// HEIGHT);
// bres->y2 = bres->y;
// TODO
// init_bres(fdf);
// bres->x = map(fdf->points.iso_x[ind], 0, fdf->x_len - 1, 0, WIDTH);
// bres->x2 = bres->x;
// bres->y = map(fdf->points.iso_y[ind], 0, fdf->y_len - 1, 0, HEIGHT);
// bres->y = map(fdf->points.iso_y[ind + fdf->x_len], 0, fdf->y_len
// 		- 1, 0, HEIGHT);
