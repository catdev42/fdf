/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:21:59 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/26 16:53:25 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*dupl;

	size = ft_strlen(s);
	dupl = malloc(sizeof(char) * (size + 1));
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dupl[i] = s[i];
		i++;
	}
	dupl[i] = 0;
	return (dupl);
}
