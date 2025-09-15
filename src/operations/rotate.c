/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:02 by omaly             #+#    #+#             */
/*   Updated: 2025/09/15 11:09:24 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Shift up all elements of stack by 1.
// The first element becomes the last one.
void	rotate_a(t_list **stack)
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
	write(1,"ra\n",3);
}

void	rotate_b(t_list **stack)
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
	write(1,"rb\n",3);
}
