/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:36:45 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:18:12 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list **lst)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*before;

	if (!lst || !(*lst))
		return ;
	second_last = *lst;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = last->next;
	last->next = second_last;
	if (*lst != second_last)
	{
		before = *lst;
		while (before->next != second_last)
			before = before->next;
		before->next = last;
	}
}

void	sa(t_ps *ps)
{
	swap(&(ps->lst_a));
	write(1, "sa\n", 3);
}

void	sb(t_ps *ps)
{
	swap(&(ps->lst_b));
	write(1, "sb\n", 3);
}

void	ss(t_ps *ps)
{
	swap(&(ps->lst_a));
	swap(&(ps->lst_b));
	write(1, "ss\n", 3);
}
