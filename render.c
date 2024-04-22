/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:00:13 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/22 18:58:43 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	init_bres(t_bres *bres);
static void	run_bres(t_bres *bres, t_image *img);
static int	my_put_pixel(int x, int y, t_image *img, int color);

void	render_lines(t_bres *bres, t_fdf *fdf)
{
	int	i;

	// int	offset;
	i = 0;
	// offset = 100 * fdf->img.line_len + 100 * (fdf->img.bpp / 8);
	// *(unsigned int *)(fdf->img.pixels_ptr + offset) = 0xffffff;
	while (i < (fdf->x_len * fdf->y_len) - 1)
	{
		bres->x = fdf->points.map_x[i];
		bres->y = fdf->points.map_y[i];
		bres->color = fdf->points.color[i];
		if (fdf->points.x[i] < fdf->x_len - 2)
		{
			bres->x2 = fdf->points.map_x[i + 1];
			bres->y2 = fdf->points.map_y[i + 1];
			init_bres(bres);
			run_bres(bres, &fdf->img);
			mlx_put_image_to_window(fdf->mlx_connection, fdf->mlx_window,
		fdf->img.img_ptr, 0, 0);
		}
		if (fdf->points.y[i] < fdf->y_len - 2)
		{
			bres->x2 = fdf->points.map_x[i + 1];
			bres->y2 = fdf->points.map_y[i + fdf->x_len];
			init_bres(bres);
			run_bres(bres, &fdf->img);
			mlx_put_image_to_window(fdf->mlx_connection, fdf->mlx_window,
		fdf->img.img_ptr, 0, 0);
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_connection, fdf->mlx_window,
		fdf->img.img_ptr, 0, 0);
}

static void	init_bres(t_bres *bres)
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

/*CALCULATES NEXT PIXEL AND PUTS IT INTO PIXEL ARRAY*/
/*INCLUDES PUT PIXEL*/
static void	run_bres(t_bres *bres, t_image *img)
{
	int	x;
	int	y;
	int	e2;
	int	err;
	int	offset;

	x = bres->x;
	y = bres->y;
	offset = 0;
	err = bres->dx - bres->dy;
	while (x != bres->x2 || y != bres->y2)
	{
		offset = y * img->line_len + x * (img->bpp / 8);
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			*(unsigned int *)(img->pixels_ptr + offset) = 0xffffff;
		e2 = 2 * err;
		if (e2 > -bres->dy)
		{
			err -= bres->dy;
			x += bres->sx;
		}
		if (e2 < bres->dx)
		{
			err += bres->dx;
			y += bres->sy;
		}
	}
}

// static int	my_put_pixel(int x, int y, t_image *img, int color)
// {
// 	int	offset;

// 	offset = y * img->line_len + x * (img->bpp / 8);
// 	*(unsigned int *)(img->pixels_ptr + offset) = color;
// }
