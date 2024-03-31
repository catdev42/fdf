/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:33:00 by myakoven          #+#    #+#             */
/*   Updated: 2023/12/09 18:19:17 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_freedel(void *temp_content, t_list *new_list, void (*del)(void *))
{
	del(temp_content);
	if (!new_list)
		return (NULL);
	ft_lstclear(&new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_listptr;
	t_list	*temp_elem;
	t_list	*new_list;
	void	*temp_content;

	if (!lst)
		return (NULL);
	temp_content = f(lst->content);
	new_list = ft_lstnew(temp_content);
	if (!new_list)
		return (ft_freedel(temp_content, NULL, del));
	temp_listptr = new_list;
	lst = lst->next;
	while (lst)
	{
		temp_content = f(lst->content);
		temp_elem = ft_lstnew(temp_content);
		if (!temp_elem)
			return (ft_freedel(temp_content, new_list, del));
		temp_listptr->next = temp_elem;
		lst = lst->next;
		temp_listptr = temp_listptr->next;
	}
	return (new_list);
}

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
	{
		return (0);
	}
	new = 0;
	// new = ft_lstnew(temp->content);
	while (lst)
	{
		temp = ft_lstnew((f)(lst->content))
		if (!temp)
		{
			ft_lst
		}
		lst = lst->next;
		temp->next = ft_lstnew((f)(lst->content));
		temp = temp->next;
	}
	return (new);
}
*/
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_elem = ft_lstnew(tmp);
		if (!new_elem)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
*/
