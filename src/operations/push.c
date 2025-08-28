/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:58 by omaly             #+#    #+#             */
/*   Updated: 2025/08/28 15:09:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parse.h"

// Take the first element at the top of stack A and put it at the top of stack B.
// Do nothing if A is empty.
// The 'top' is the node where node->next == NULL
void push(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return;

	t_list *last_a;
	t_list *before_last_a;
	last_a = *stack_a;
	before_last_a = NULL;

	while (last_a->next != NULL)
	{
		before_last_a = last_a;
		last_a = last_a->next;
	}

	if (before_last_a)
	{
		before_last_a->next = NULL;
	}
	else {
		*stack_a = NULL;
	}

	if (*stack_b == NULL)
	{
		*stack_b = last_a;
		last_a->next = NULL;
	}
	else {
		t_list *last_b = *stack_b;
		while (last_b->next)
			last_b = last_b->next;

		last_b->next = last_a;
		last_a->next = NULL;
	}
}
