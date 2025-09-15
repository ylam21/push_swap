/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/15 11:08:34 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Shift down all elements of stack by 1.
// The last element becomes the first one.
void	reverse_rotate_a(t_list **stack)
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
	write(1,"rra\n",4);
}

void	reverse_rotate_b(t_list **stack)
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
	write(1,"rrb\n",4);
}
