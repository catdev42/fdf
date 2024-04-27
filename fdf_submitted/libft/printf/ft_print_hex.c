/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:24:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 17:20:13 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_print_it(uintptr_t address);
static int	ft_print_it_hex(unsigned int num, char format);

int	ft_printptr(uintptr_t address)
{
	int	count;

	count = 0;
	if (address == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_print_it(address) == -1)
		return (-1);
	while (address > 0)
	{
		address = address / 16;
		count++;
	}
	return (count + 2);
}

static int	ft_print_it(uintptr_t address)
{
	while (address > 15)
	{
		ft_print_it(address / 16);
		address = address % 16;
	}
	if (address <= 9)
		if (ft_printchar((address + '0')) == -1)
			return (-1);
	if (address > 9)
		if (ft_printchar((address + 'a' - 10)) == -1)
			return (-1);
	return (0);
}

int	ft_printhex(unsigned int num, char format)
{
	int	count;

	count = 0;
	if (!num)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_print_it_hex(num, format) == -1)
		return (-1);
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static int	ft_print_it_hex(unsigned int num, char format)
{
	while (num > 15)
	{
		if (ft_print_it_hex(num / 16, format) == -1)
			return (-1);
		num = num % 16;
	}
	if (num <= 9)
	{
		if (ft_printchar((num + '0')) == -1)
			return (-1);
	}
	if (num > 9)
	{
		if (format == 'x')
		{
			if (ft_printchar((num + 'a' - 10)) == -1)
				return (-1);
		}
		else
		{
			if (ft_printchar((num + 'A' - 10)) == -1)
				return (-1);
		}
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("chars in 143 as hex: %i", ft_printptr(143));
}
*/
