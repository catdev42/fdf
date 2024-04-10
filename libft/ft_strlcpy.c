/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:27:20 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/26 16:53:04 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size == 0)
		return (ft_strlen(src));
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

/*
function copies the string and returns the length of the string
it tried to create

if dist == 0, return the length of src
while i < size(of dest) and src is not nul terminate keep counting i
*/
