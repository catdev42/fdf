/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 21:25:54 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./include/fractol.h"

double	scale(double unscaled_num, double n_min, double n_max, double o_min,
		double o_max)
{
	double	nnum;

	nnum = (n_max - n_min) * (unscaled_num - o_min) / (o_max - o_min) + n_min;
	return (nnum);
}