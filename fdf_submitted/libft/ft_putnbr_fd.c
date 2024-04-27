/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:03:10 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/26 22:20:26 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	n = n % 10;
	ft_putchar_fd((n % 10 + 48), fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(-4212345, 1);
}
*/
/* A file descriptor of 0, 1, or 2, refers to
the standard input, standard output, or standard error, respectively */
