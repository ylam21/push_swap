/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:58 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 14:55:03 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*pop_last(t_list **lst)
{
	t_list	*last;
	t_list	*before;

	if (!lst || !(*lst))
		return (NULL);
	last = *lst;
	before = NULL;
	while (last->next)
	{
		before = last;
		last = last->next;
	}
	if (before)
		before->next = NULL;
	else
		*lst = NULL;
	return (last);
}

// Take the first element at the top of stack A
// and put it at the top of stack B.
// Do nothing if A is empty.
// The 'top' is the node where node->next == NULL
void	push(t_list **src, t_list **dest)
{
	t_list	*last_src;
	t_list	*last_dest;

	if (!src || !(*src))
		return ;
	last_src = pop_last(src);
	if (!last_src)
		return ;
	if (!(*dest))
		*dest = last_src;
	else
	{
		last_dest = ft_lstlast(*dest);
		last_dest->next = last_src;
	}
}

void	pa(t_ps *ps)
{
	push(&(ps->stack_b), &(ps->stack_a));
	write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	push(&(ps->stack_a), &(ps->stack_b));
	write(1, "pb\n", 3);
}
