/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:20:33 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/26 21:51:59 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(int n)
{
	size_t		len;
	long int	num;

	num = n;
	len = 1;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = ft_length(num);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len] = 0;
	while (num >= 10)
	{
		str[len - 1] = num % 10 + 48;
		num /= 10;
		len--;
	}
	str[len - 1] = num + 48;
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(-2147483648LL);
	printf("number 42 becomes: '%s'", str);
}
*/
