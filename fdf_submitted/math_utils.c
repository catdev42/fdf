/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:23:41 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/24 16:59:16 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	hex_to_int(char c);

/*
 * take the value that starts with original min,
 * divide by original range to get a percentage, multiply by target range,
 * add target min
 */

int	ahextoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] == '0' && nptr[i + 1] == 'x')
		i += 2;
	else
		return (0);
	while ((nptr[i] >= '0' && nptr[i] <= '9') || (nptr[i] >= 'A'
			&& nptr[i] <= 'F') || (nptr[i] >= 'a' && nptr[i] <= 'f'))
		num = num * 16 + hex_to_int(nptr[i++]);
	return (num * sign);
}

static int	hex_to_int(char c)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if ("0123456789ABCDEF"[i] == c)
			return (i);
		if ("0123456789abcdef"[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
//MAP FUNCTION NOT FUNCTIONAL
double	map(double unscaled_num, double	original_min, double original_max,
			double target_min,
		double target_max)
{
	return ((unscaled_num - original_min) / (original_max - original_min)
		* (target_max - target_min) + target_min);
}
*/
