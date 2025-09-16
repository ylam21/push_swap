/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:39:43 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 14:49:12 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

unsigned int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (size);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstnew(int value)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->rank = value;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (!lst || !*lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = newlst;
}
