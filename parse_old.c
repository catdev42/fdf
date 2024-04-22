/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:14:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/22 20:07:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	parse_line(char *dataline, t_fdf *fdf, int index);
static int	calculate_isometric(t_fdf *fdf);
static int	get_color(const char *single_map_item, int index, t_fdf *fdf);
static void	calc_min_max_iso(t_fdf *fdf);

/*Malloc
 *Open File
 *Parse each line (function)
 *Get iso_x and iso_y (function)
 * */
int	parse_data(int fd, t_fdf *fdf)
{
	int		index;
	char	*dataline;

	index = 0;
	dataline = NULL;
	fdf->points.x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	fdf->points.y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	fdf->points.z = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	fdf->points.color = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.iso_x = ft_calloc((fdf->x_len * fdf->y_len + 2),
			sizeof(double));
	fdf->points.iso_y = ft_calloc((fdf->x_len * fdf->y_len + 2),
			sizeof(double));
	fdf->points.map_x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.map_y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	// fdf->points.map_z = ft_calloc((fdf->x_len * fdf->y_len + 2), 4);
	if (!fdf->points.x || !fdf->points.y || !fdf->points.z || !fdf->points.color
		|| !fdf->points.iso_x || !fdf->points.iso_y || !fdf->points.map_x
		|| !fdf->points.map_y)
		fdf_clean(fdf, 1);
	while (index < fdf->x_len * fdf->y_len)
	{
		dataline = get_next_line(fd);
		if (!dataline)
			break ;
		index = parse_line(dataline, fdf, index);
	}
	calculate_isometric(fdf);
	calc_min_max_iso(fdf);
	calculate_translation(fdf, &fdf->points);
	return (1);
}

static int	parse_line(char *dataline, t_fdf *fdf, int index)
{
	int		x;
	int		y;
	char	**alpha_dataline_split;
	int		i;

	i = index;
	// while (fdf->points.x[index])
	// 	index++;
	x = 0;
	y = 0;
	if (index)
		y = fdf->points.y[i - 1] + 1;
	if (dataline[ft_strlen(dataline) - 1] == '\n')
		dataline[ft_strlen(dataline) - 1] = 0;
	alpha_dataline_split = ft_split(dataline, ' ');
	if (!alpha_dataline_split)
		fdf_clean(fdf, 1);
	while (alpha_dataline_split[x])
	{
		fdf->points.x[i] = x;
		fdf->points.y[i] = y;
		if (!get_color(alpha_dataline_split[x], i, fdf))
		{
			free_split(alpha_dataline_split);
			fdf_clean(fdf, 1);
		}
		x++;
		i++;
	}
	return (i);
}

static int	get_color(const char *single_map_item, int index, t_fdf *fdf)
{
	char	**color_data_split;

	if (!ft_strchr(single_map_item, ','))
	{
		fdf->points.color[index] = 0;
		fdf->points.z[index] = atoi(single_map_item);
	}
	else
	{
		color_data_split = ft_split(single_map_item, ',');
		if (!color_data_split)
			return (0);
		fdf->points.z[index] = atoi(color_data_split[0]);
		fdf->points.color[index] = ahextoi(color_data_split[1]);
		free_split(color_data_split);
	}
	if (fdf->points.z[index] < fdf->z_min)
		fdf->z_min = fdf->points.z[index];
	if (fdf->points.z[index] > fdf->z_max)
		fdf->z_max = fdf->points.z[index];
	return (1);
}

static int	calculate_isometric(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < (fdf->x_len * fdf->y_len) && !fdf->points.iso_x[i])
	{
		fdf->points.iso_x[i] = (fdf->points.x[i] - fdf->points.y[i])
			* cos(fdf->angle);
		fdf->points.iso_y[i] = (fdf->points.x[i] + fdf->points.y[i])
			* sin(fdf->angle) - fdf->points.z[i];
		// CHECK MAX MIN
		// if (fdf->points.iso_x[i] < fdf->points.orig_min)
		// 	fdf->points.orig_min = fdf->points.iso_x[i];
		// if (fdf->points.iso_y[i] < fdf->points.orig_min)
		// 	fdf->points.orig_min = fdf->points.iso_y[i];
		// if (fdf->points.iso_x[i] > fdf->points.orig_max)
		// 	fdf->points.orig_max = fdf->points.iso_x[i];
		// if (fdf->points.iso_y[i] > fdf->points.orig_max)
		// 	fdf->points.orig_max = fdf->points.iso_y[i];
		i++;
	}
	// fdf->points.orig_min = floor(fdf->points.orig_min);
	// fdf->points.orig_max = ceil(fdf->points.orig_min);
	return (1);
}

/*is_iso is bool*/
static void	calc_min_max_iso(t_fdf *fdf)
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

/*ANY TIME THERE IS A TRANSLATE OR ZOOM, THIS NEEDS TO BE RECALCULATED
***AFTER CHANGE IN ORIG MIN AND ORIG MAX & TARGET MIN AND TARGET MAX*/
int	calculate_translation(t_fdf *fdf, t_points *points)
{
	size_t	i;
	double	temp_x;
	double	temp_y;
	int		count;

	i = 0;
	count = 0;
	while (count < 12)
	{
		printf("%d: x: %f , y: %f \n", count++, points->iso_x[count],
			points->iso_y[count]);
	}
	while (i < (fdf->x_len * fdf->y_len))
	{
		temp_x = (points->iso_x[i] - points->orig_min) / (points->orig_max
				- points->orig_min) * (points->target_max - points->target_min)
			+ points->target_min;
		temp_y = (points->iso_y[i] - points->orig_min) / (points->orig_max
				- points->orig_min) * (points->target_max - points->target_min)
			+ points->target_min;
		points->map_x[i] = (int)temp_x;
		points->map_y[i] = (int)temp_y;
		i++;
	}
	count = 0;
	while (count < 12)
	{
		printf("%i: x: %i , y: %i \n", count++, points->map_x[count],
			points->map_y[count]);
	}
	return (1);
}
