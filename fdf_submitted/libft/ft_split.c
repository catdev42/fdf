/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:21:22 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/18 22:06:15 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_wordcount(char const *s, char c);
static char	**ft_free_split(char **arr, size_t index);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_counter;
	size_t	word_len;

	arr = ft_calloc((ft_wordcount(s, c) + 1), sizeof(char *));
	if (!arr || !s)
		return (ft_free_split(arr, 0));
	arr_counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		word_len = ft_strlen(s);
		if (ft_strchr(s, c))
			word_len = ft_strchr(s, c) - s;
		arr[arr_counter++] = ft_substr(s, 0, word_len);
		if (!arr[arr_counter - 1])
			return (ft_free_split(arr, (arr_counter - 1)));
		s += word_len;
	}
	if (!arr_counter)
		arr[arr_counter++] = ft_strdup("");
	return (arr);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static char	**ft_free_split(char **arr, size_t index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	if (arr)
		free(arr);
	return (NULL);
}
/* took out of ft_split cause calloc
	arr[arr_counter] = NULL;
*/
