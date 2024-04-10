/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:29:47 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/11 20:12:43 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)big;
	if (!(*little))
		return (str);
	if (!big || !ft_strlen(big))
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i + j] && str[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
