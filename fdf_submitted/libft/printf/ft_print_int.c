/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:14:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/24 16:57:10 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char		*ft_itoa_printf(int n);
static size_t	ft_length(int n);

int	ft_printnum(int n)
{
	int		count;
	char	*numstr;

	count = 0;
	numstr = ft_itoa_printf(n);
	if (!numstr)
		return (-1);
	count = ft_printstr(numstr);
	free(numstr);
	return (count);
}

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

static char	*ft_itoa_printf(int n)
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
