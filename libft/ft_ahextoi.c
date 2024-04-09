/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahextoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:11:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/09 21:22:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_to_int(char c);

int	ft_ahextoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;
	int	hextoint;

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
	if (nptr[i] == "0" && nptr[i + 1] == 'x')
		i += 2;
	else
		return (0);
	while (ft_strchr(nptr))
	{
		hextoint = hex_to_int(nptr[i], "0123456789abcdef", "0123456789ABCDEF");
		if (hextoint == -1)
			return (0);
		num = num * 16 + hextoint;
		i++;
	}
	return (num * sign);
}

static int	hex_to_int(char c, char *hex_lower, char *hex_upper)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (c == hex_lower || c == hex_upper)
			return (i);
		i++;
	}
	return (-1);
	// on error return -1
}
