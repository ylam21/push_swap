/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:00 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:33:42 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Shift down all elements of stack by 1.
// The last element becomes the first one.
void	reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*curr;

	if (!lst || !(*lst)->next)
		return ;
	head = *lst;
	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = head;
	*lst = head->next;
	curr->next->next = NULL;
}

void	rra(t_ps *ps)
{
	reverse_rotate(&(ps->lst_a));
	write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	reverse_rotate(&(ps->lst_a));
	write(1, "rrb\n", 4);
}

void	rrr(t_ps *ps)
{
	reverse_rotate(&(ps->lst_a));
	reverse_rotate(&(ps->lst_b));
	write(1, "rrr\n", 4);
}
