/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:21:36 by omaly            ###   ########.fr       */
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
