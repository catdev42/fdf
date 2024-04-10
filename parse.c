/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:14:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/10 14:44:48 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	parse_line(char *dataline, t_fdf *fdf, int *index);
static int	calculate_isometric(t_fdf *fdf);
static int	get_color(char *single_map_item, int index, t_fdf *fdf);

/*Malloc
 *Open File
 *Parse each line (function)
 *Get iso_x and iso_y (function)
 * */
int	parse_data(int fd, t_fdf *fdf)
{
	char	**alpha_dataline_split;
	char	**color_data_split;
	int		index;
	char	*dataline;

	// MALLOC
	fdf->points.x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.y = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.z = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.color = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.iso_x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	fdf->points.iso_x = ft_calloc((fdf->x_len * fdf->y_len + 2), sizeof(int));
	if (!fdf->points.x || !fdf->points.y || !fdf->points.z || !fdf->points.color
		|| !fdf->points.iso_x || !fdf->points.iso_y)
		fdf_clean(fdf, 1);
	// PARSE DATA INTO FDF->POINTS
	while (index < fdf->x_len * fdf->y_len)
	{
		dataline = get_next_line(fd);
		if (!dataline)
			break ;
		// // CHECK IF THIS SEG FAULTS //REMOVE
		// printf("This is working Index == %i \n", index);
		index = parse_line(dataline, fdf, &index);
		// printf("This is still working and index \
		// 	+ 1 should divide by Y (%f)Index == %i \n",
		// 		index);
	}
	calculate_isometric(fdf);
	return (1);
}

static int	parse_line(char *dataline, t_fdf *fdf, int *index)
{
	int		x;
	int		y;
	char	**alpha_dataline_split;

	x = 0;
	y = *index / fdf->x_len + 1;
	if (ft_strlen(dataline) - 1 == '\n')
		dataline[ft_strlen(dataline) - 1] = 0;
	alpha_dataline_split = ft_split(dataline, ' ');
	if (!alpha_dataline_split)
		fdf_clean(fdf, 1);
	while (alpha_dataline_split[x])
	{
		fdf->points.x[*index] = x;
		fdf->points.y[*index] = y;
		if (!get_color(alpha_dataline_split[x], *index, fdf))
		{
			free(alpha_dataline_split);
			fdf_clean(fdf, 1);
		}
		free(alpha_dataline_split);
		x++;
		*index++;
	}
}

static int	get_color(char *single_map_item, int index, t_fdf *fdf)
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
	}
	free(color_data_split);
	return (1);
}

static int	calculate_isometric(t_fdf *fdf)
{
	return (1);
}
