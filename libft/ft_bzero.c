/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:35:37 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/09 21:05:07 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_hextoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && *nptr <= 13))
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
	while (nptr == '0' && nptr[])
		while (*nptr >= '0' && *nptr <= '9')
		{
			num = num * 10 + (*nptr - 48);
			nptr++;
		}
	return (num * sign);
}
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i++] = '\0';
	}
}
