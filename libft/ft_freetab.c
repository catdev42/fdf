/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:09:28 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/17 21:54:40 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **arr, int len)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	if (len <= 0)
		len = INT_MAX;
	while (arr[i] && i < len)
		free(arr[i++]);
	free(arr);
}
