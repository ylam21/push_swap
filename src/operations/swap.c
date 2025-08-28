/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:05 by omaly             #+#    #+#             */
/*   Updated: 2025/08/28 14:28:30 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parse.h"
#include <stdio.h>

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
// The 'top' is the node where node->next == NULL
void swap(t_list **list)
{
	if (!list || !*list || !(*list)->next)
		return;

	t_list *last;
	t_list *before_last;
	t_list *before_before_last;

	last = *list;
	before_last = NULL;

	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}

	// Case where there is only 1 node, nothing to swap
	if (before_last == NULL)
		return;

	before_before_last = *list;

	// Case where there is only 2 nodes
	if (before_last == before_before_last)
	{
		last->next = before_last;
		before_last->next = NULL;
		*list = last;
		return;
	}

	// More than 2 nodes
	while (before_before_last->next != before_last)
		before_before_last = before_before_last->next;

	before_before_last->next = last;
	last->next = before_last;
	before_last->next = NULL;
	return;
}
