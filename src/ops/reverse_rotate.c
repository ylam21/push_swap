/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 14:46:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Shift down all elements of stack by 1.
// The last element becomes the first one.
void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*curr;

	if (!stack || !(*stack)->next)
		return ;
	head = *stack;
	curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = head;
	*stack = head->next;
	curr->next->next = NULL;
}

void	rra(t_ps *ps)
{
	reverse_rotate(&(ps->stack_a));
	write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	reverse_rotate(&(ps->stack_a));
	write(1, "rrb\n", 4);
}

void	rrr(t_ps *ps)
{
	reverse_rotate(&(ps->stack_a));
	reverse_rotate(&(ps->stack_b));
	write(1, "rrr\n", 4);
}
