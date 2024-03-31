/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:13:23 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/11 20:09:43 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdest;

	if (!dest && !src)
		return (NULL);
	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (pdest);
}

/*
#include <stdio.h>
#include <stddef.h>

int main() {
    char src[] = "Hello, world!";
    char dst[14];

    ft_memcpy(dst, src, 13);
    dst[14] = '\0'; // Add a null terminator

    printf("Destination array: %s\n", dst);

    return 0;
}
*/
/*
SYNOPSIS
		#include <string.h>

		void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
		The  memcpy()  function  copies  n bytes from memory area src to memory
		area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
		memory areas do overlap.
*/