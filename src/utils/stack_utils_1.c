/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 15:22:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = curr->rank;
	while (curr)
	{
		if (curr->rank < min)
			min = curr->rank;
		curr = curr->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = curr->rank;
	while (curr)
	{
		if (curr->rank > max)
			max = curr->rank;
		curr = curr->next;
	}
	return (max);
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
		max = curr->rank;
		if (max < curr->next->rank)
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
		min = curr->rank;
		if (min > curr->next->rank)
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
		if (curr->rank == find)
			return (index);
		index++;
		curr = curr->next;
	}
	return (-1);
}
