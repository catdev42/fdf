/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:14:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/23 18:24:24 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	parse_line(char *dataline, t_fdf *fdf, int index);
static int	get_color(const char *single_map_item, int index, t_fdf *fdf);

/*Malloc
 *Open File
 *Parse each line (function)
 *Get iso_x and iso_y nad map_x map_y (function)
 * */
void	parse_data(int fd, t_fdf *fdf, t_points *points)
{
	int		index;
	char	*dataline;

	index = 0;
	dataline = NULL;
	points->y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	points->x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	points->z = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	points->color = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	points->iso_x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	points->iso_y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(double));
	points->map_x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	points->map_y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	if (!points->x || !points->y || !points->z || !points->color
		|| !points->iso_x || !points->iso_y || !points->map_x || !points->map_y)
		fdf_clean(fdf, 1);
	while (index < fdf->x_len * fdf->y_len)
	{
		dataline = get_next_line(fd);
		if (!dataline)
			break ;
		index = parse_line(dataline, fdf, index);
		free(dataline);
	}
}

static int	parse_line(char *dataline, t_fdf *fdf, int i)
{
	int		x;
	int		y;
	char	**alpha_dataline_split;

	x = 0;
	y = 0;
	if (i)
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
		if (!get_color(alpha_dataline_split[x++], i++, fdf))
		{
			free_split(alpha_dataline_split);
			fdf_clean(fdf, 1);
		}
	}
	free_split(alpha_dataline_split);
	return (i);
}

static int	get_color(const char *single_map_item, int index, t_fdf *fdf)
{
	char	**color_data_split;

	if (!ft_strchr(single_map_item, ','))
	{
		fdf->points.color[index] = 0xffffff;
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

/*
COL SHIFT

uint32_t	shift_col(t_fdf *fdf)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;

	alpha = fdf->col >> 24 & 0xff;
	red = fdf->col >> 16 & 0xff;
	;
	green = fdf->col >> 8 & 0xff;
	blue = fdf->col & 0xff;
	if (green > 10 && blue > 10)
	{
		green = green - 5;
		blue = blue - 5;
	}
	fdf->col = (alpha << 24 | red << 16 | green << 8 | blue);
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

ANY TIME THERE IS A TRANSLATE OR ZOOM, THIS NEEDS TO BE RECALCULATED
***AFTER CHANGE IN ORIG MIN AND ORIG MAX & TARGET MIN AND TARGET MAX
*/
