/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:14:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/09 01:02:48 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	parse_data(char *dataline, t_fdf *fdf)
{
	int i;
	char **alpha_dataline_split;

	i = 0;
	if (ft_strlen(dataline) - 1 == '\n')
		dataline[ft_strlen(dataline) - 1] = 0;
	alpha_dataline_split = ft_split(dataline, ' ');

	i = 0;
	while (alpha_dataline_split[i])
	{
		if (ft_strchr(alpha_dataline_split[i], ','))
			fdf->points.color[i] = i++;
	}
}