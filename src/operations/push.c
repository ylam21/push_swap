/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:58 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 12:40:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/utils.h"

// Take the first element at the top of stack A and put it at the top of stack B.
// Do nothing if A is empty.
// The 'top' is the node where node->next == NULL

void push(t_list **src, t_list **dest)
{
	if (!src || !(*src))
		return;

	t_list *last;
	t_list *before_last;
	last = *src;
	before_last = NULL;

	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}

	if (before_last)
		before_last->next = NULL;
	else
		*src = NULL;

	if (*dest == NULL)
		*dest = last;
	else {
		t_list *last_dest = *dest;
		while (last_dest->next)
			last_dest = last_dest->next;
		last_dest->next = last;
	}
	last->next = NULL;
}
