/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcpoints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:35:54 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/22 23:00:34 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	calculate_isometric(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < (fdf->x_len * fdf->y_len) && !fdf->points.iso_x[i])
	{
		fdf->points.iso_x[i] = (fdf->points.x[i] - fdf->points.y[i])
			* cos(fdf->angle);
		fdf->points.iso_y[i] = (fdf->points.x[i] + fdf->points.y[i])
			* sin(fdf->angle) - fdf->points.z[i];
		i++;
	}
	calc_min_max_iso(fdf);
	return (1);
}

void	calc_min_max_iso(t_fdf *fdf)
{
	t_points	*points;
	int			i;

	i = 0;
	points = &fdf->points;
	points->orig_min = INT_MAX;
	points->orig_max = INT_MIN;
	while (i < (fdf->x_len * fdf->y_len))
	{
		if (points->iso_x[i] < points->orig_min)
			points->orig_min = points->iso_x[i];
		if (points->iso_y[i] < points->orig_min)
			points->orig_min = points->iso_y[i];
		if (points->iso_x[i] > points->orig_max)
			points->orig_max = points->iso_x[i];
		if (points->iso_y[i] > points->orig_max)
			points->orig_max = points->iso_y[i];
		i++;
	}
}

int	calculate_translation(t_fdf *fdf, t_points *points)
{
	double	temp_x;
	double	temp_y;
	int		i;

	i = 0;
	temp_x = 0;
	temp_y = 0;
	while (i < (fdf->x_len * fdf->y_len))
	{
		temp_x = ((points->iso_x[i] - points->orig_min) / (points->orig_max
					- points->orig_min) * (points->target_max
					- points->target_min) + points->target_min);
		temp_y = ((points->iso_y[i] - points->orig_min) / (points->orig_max
					- points->orig_min) * (points->target_max
					- points->target_min) + points->target_min);
		points->map_x[i] = (int)temp_x;
		points->map_y[i] = (int)temp_y;
		i++;
	}
	return (1);
}
