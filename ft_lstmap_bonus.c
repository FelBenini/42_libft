/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:20:57 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/19 21:16:33 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*next_lst;

	if (!lst || !f || !del)
		return (0);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (0);
	lst = lst->next;
	while (lst)
	{
		next_lst = ft_lstnew((*f)(lst->content));
		if (!next_lst)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, next_lst);
		lst = lst->next;
	}
	return (new_lst);
}
