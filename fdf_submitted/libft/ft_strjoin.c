/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:21:50 by myakoven          #+#    #+#             */
/*   Updated: 2023/11/26 16:54:59 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*string;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	string = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!(string))
		return (NULL);
	while (i < (len_s1))
	{
		string[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		string[i++] = s2[j++];
	}
	string[i] = 0;
	return (string);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*newstr;

	s1 = "hello ";
	s2 = "there!";
	newstr = ft_strjoin(s1, s2);
	printf("the new string is '%s'", newstr);
}
*/
