/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:02 by omaly             #+#    #+#             */
/*   Updated: 2025/08/31 15:54:23 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/utils.h"

// Shift up all elements of stack by 1.
// The first element becomes the last one.
void rotate(t_list **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	t_list *curr = *stack;
	t_list *prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

