/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:02:10 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 17:22:08 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_checkcase(va_list args, const char format);

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		checker;

	count = 0;
	i = -1;
	if (!string)
		return (-1);
	va_start(args, string);
	while (string[++i])
	{
		if (string[i] == '%')
			checker = ft_checkcase(args, string[++i]);
		else
			checker = ft_printchar(string[i]);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	va_end(args);
	return (count);
}

static int	ft_checkcase(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == '%')
		count += ft_printchar('%');
	else if (format == 'd' || format == 'i')
		count += ft_printnum(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
	else if (format == 'u')
		count += ft_printuns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(args, unsigned long long int), format);
	else
		return (-1);
	return (count);
}
