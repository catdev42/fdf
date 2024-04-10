/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:43:41 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/09 17:07:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}

/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		prev = tmp;
		del(tmp->content);
		tmp = tmp->next;
		free(prev);
	}
	*lst = 0;
}
*/
