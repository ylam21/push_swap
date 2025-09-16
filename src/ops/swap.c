/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:36:45 by omaly             #+#    #+#             */
/*   Updated: 2025/09/15 15:57:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*before;

	if (!stack || !(*stack))
		return ;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = last->next;
	last->next = second_last;
	if (*stack != second_last)
	{
		before = *stack;
		while (before->next != second_last)
			before = before->next;
		before->next = last;
	}
}

void	sa(t_ps *ps)
{
	swap(&(ps->stack_a));
	write(1, "sa\n", 3);
}
void	sb(t_ps *ps)
{
	swap(&(ps->stack_b));
	write(1, "sb\n", 3);
}
void	ss(t_ps *ps)
{
	swap(&(ps->stack_a));
	swap(&(ps->stack_b));
	write(1, "ss\n", 3);
}
