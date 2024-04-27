/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:14:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/31 17:17:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_uitoa_printf(unsigned int u);
static int	ft_unslen(unsigned int u);

int	ft_printuns(unsigned int u)
{
	char	*numstr;

	numstr = ft_uitoa_printf(u);
	if (!numstr)
		return (-1);
	if (ft_printstr(numstr) == -1)
	{
		free(numstr);
		return (-1);
	}
	free(numstr);
	return (ft_unslen(u));
}

static char	*ft_uitoa_printf(unsigned int u)
{
	size_t	len;
	char	*numstr;

	len = ft_unslen(u);
	numstr = malloc(sizeof(char) * (len + 1));
	if (!numstr)
		return (NULL);
	numstr[len] = 0;
	while (len > 0)
	{
		numstr[--len] = u % 10 + '0';
		u /= 10;
	}
	return (numstr);
}

static int	ft_unslen(unsigned int u)
{
	int	i;

	i = 0;
	if (u == 0)
		return (1);
	while (u > 0)
	{
		u = u / 10;
		i++;
	}
	return (i);
}
