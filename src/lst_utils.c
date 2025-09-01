/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:39:43 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 16:09:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstnew(int d)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->d = d;
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

int	is_descending(t_list *lst)
{
	int		max;
	t_list	*curr;

	if (!lst || lst->next == NULL)
		return (1);
	curr = lst;
	while (curr->next)
	{
		max = curr->d;
		if (max < curr->next->d)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_ascending(t_list *lst)
{
	int		min;
	t_list	*curr;

	if (!lst || lst->next == NULL)
		return (1);
	curr = lst;
	while (curr->next)
	{
		min = curr->d;
		if (min > curr->next->d)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	get_index(t_list *lst, int find)
{
	int		index;
	t_list	*curr;

	if (!lst)
		return (-1);
	index = 0;
	curr = lst;
	while (curr)
	{
		if (curr->d == find)
			return (index);
		index++;
		curr = curr->next;
	}
	return (-1);
}
