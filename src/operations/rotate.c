/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:02 by omaly             #+#    #+#             */
/*   Updated: 2025/09/15 15:55:33 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Shift up all elements of stack by 1.
// The first element becomes the last one.
void	rotate(t_list **stack)
{
	t_list	*curr;
	t_list	*prev;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	curr = *stack;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

void	ra(t_ps *ps)
{
	rotate(&(ps->stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	rotate(&(ps->stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	rotate(&(ps->stack_a));
	rotate(&(ps->stack_b));
	write(1, "rr\n", 3);
}
