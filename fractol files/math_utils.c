/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/10 14:50:58 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

// double	map(double unscaled_num, double n_min, double n_max, double o_min,
// 		double o_max)
// {
// 	double	nnum;

// 	nnum = (n_max - n_min) * (unscaled_num - o_min) / (o_max - o_min) + n_min;
// 	return (nnum);
// }

double	map(double unscaled_num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

/*SUM_COMLEX is basically vector addition*/
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*SQUARE COMPLEX is trickier
 *
 *   real = x^2 - y^2
 *   imaginary = 2*x*y
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	atodbl(char *s, t_fractal * fractal)
{
	long	integer;
	double	fractional;
	double	pow;
	int		sign;

	sign = +1;
	pow = 1;
	integer = 0;
	fractional = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s && ft_isdigit(*s))
		integer = integer * 10 + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s && ft_isdigit(*s))
	{
		pow = pow / 10;
		fractional = fractional + (*s++ - 48) * pow;
	}
	if (*s && !ft_isdigit(*s))
	fractol_clean(fractal, 2);
	return ((integer + fractional) * sign);
}
