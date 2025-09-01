/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:05 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 16:20:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

// Swap the first 2 elements at the top of stack
// Do nothing if there is only one element or none.
// The 'top' is the node where node->next == NULL
void	swap(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;
	t_list	*before_before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	// Case where there is only 1 node, nothing to swap
	if (before_last == NULL)
		return ;
	before_before_last = *stack;
	// Case where there is only 2 nodes
	if (before_last == before_before_last)
	{
		last->next = before_last;
		before_last->next = NULL;
		*stack = last;
		return ;
	}
	// More than 2 nodes
	while (before_before_last->next != before_last)
		before_before_last = before_before_last->next;
	before_before_last->next = last;
	last->next = before_last;
	before_last->next = NULL;
}
