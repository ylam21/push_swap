/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 12:32:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = *(int *)curr->content;
	while (curr)
	{
		if (*(int *)curr->content < min)
			min = *(int *)curr->content;
		curr = curr->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = *(int *)curr->content;
	while (curr)
	{
		if (*(int *)curr->content > max)
			max = *(int *)curr->content;
		curr = curr->next;
	}
	return (max);
}

int	is_descending(t_list *lst)
{
	int		max;
	t_list	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next)
	{
		max = *(int *)curr->content;
		if (max < *(int *)curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
