/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 12:40:40 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/utils.h"

// Shift down all elements of stack by 1.
// The last element becomes the first one.
void reverse_rotate(t_list **stack)
{
	if (!stack || !(*stack)->next)
		return;
	t_list *head =  *stack;
	t_list *curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = head;
	*stack = head->next;
	curr->next->next = NULL;
}
