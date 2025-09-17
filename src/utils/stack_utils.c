/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 21:26:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = curr->content;
	while (curr)
	{
		if (curr->content > max)
			max = curr->content;
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
		max = curr->content;
		if (max < curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
