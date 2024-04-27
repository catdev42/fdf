/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:22:03 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/06 21:29:49 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrim;

	if (!s1)
		return (NULL);
	if (!set || !ft_strlen(set) || !ft_strlen(s1))
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && (int)end >= 0)
		end--;
	strtrim = malloc(sizeof(char) * (end - start + 2));
	if (!strtrim)
		return (NULL);
	ft_strlcpy(strtrim, &s1[start], (end - start + 2));
	return (strtrim);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*string;
	char	*s1;
	char	*set;

	s1 = "my string is here my";
	set = "my";
	string = ft_strtrim(s1, set);
	printf("the new string from 'my string is here my': %s", string);
}
*/
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	new_len;
	size_t	i;
	char	*strtrim;

	set_len = ft_strlen(set);
	new_len = ft_strlen(s1);
	if (ft_strncmp(s1, set, set_len) == 0)
	{
		new_len = new_len - set_len;
		s1 += set_len;
	}
	if (ft_strncmp((s1 + new_len - set_len), set, set_len) == 0)
		new_len -= set_len;
	strtrim = malloc(sizeof(char) * new_len + 1);
	if (!strtrim)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		strtrim[i++] = *s1;
		s1++;
	}
	strtrim[i] = 0;
	return (strtrim);
}
*/
