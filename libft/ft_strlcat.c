/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:27:50 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/09 19:41:40 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	j;

	if (!dst)
		return (0);
	if (dst_size == 0)
		return (ft_strlen(src));
	if (dst_size > (ft_strlen(src) + ft_strlen(dst) + 1))
		dst_size = (ft_strlen(src) + ft_strlen(dst) + 1);
	i = 0;
	while (dst[i] && i < dst_size)
	{
		i++;
	}
	j = 0;
	while ((i + j) < dst_size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dst_size)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
	{
		return (0);
	}
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
int	main(void)
{
	char	dest[2];

	ft_strlcat(dest, "CCCCCAAAAAAAAA", -1);
	return (0);
}
*/
