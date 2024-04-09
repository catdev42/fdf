/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:18:59 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/09 21:04:53 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '+')
			nptr++;
		else if (*nptr == '-')
		{
			sign = -1;
			nptr++;
		}
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * sign);
}

long	ft_atol(const char *nptr)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '+')
			nptr++;
		else if (*nptr == '-')
		{
			sign = -1;
			nptr++;
		}
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * sign);
}

// int	ft_hextoi(const char *nptr)
// {
// 	int	num;
// 	int	sign;
// 	int	i;

// 	num = 0;
// 	sign = 1;
// 	i = 0;
// 	while (nptr[i] == ' ' || (nptr[i] >= 9 && *nptr <= 13))
// 		nptr++;
// 	if (*nptr == '-' || *nptr == '+')
// 	{
// 		if (*nptr == '+')
// 			nptr++;
// 		else if (*nptr == '-')
// 		{
// 			sign = -1;
// 			nptr++;
// 		}
// 	}
// 	while (nptr == '0' && nptr[])
// 		while (*nptr >= '0' && *nptr <= '9')
// 		{
// 			num = num * 10 + (*nptr - 48);
// 			nptr++;
// 		}
// 	return (num * sign);
// }

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("the number '    -42YESWHY' = %i\n", ft_atoi("---42"));
	printf("the number '    -42YESWHY' = %i\n", atoi("---42"));
	printf("the number '598ABC' = %i\n", ft_atoi("598ABC"));
	printf("the number '598ABC' = %i\n", atoi("598ABC"));
}
*/
