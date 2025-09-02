/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 11:18:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = curr->d;
	while (curr)
	{
		if (curr->d < min)
			min = curr->d;
		curr = curr->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = curr->d;
	while (curr)
	{
		if (curr->d > max)
			max = curr->d;
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
