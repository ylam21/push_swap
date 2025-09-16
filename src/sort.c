/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 15:18:01 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_3(t_ps *ps)
{
	int min = get_min(ps->stack_a);
	int max = get_max(ps->stack_a);
	t_list *tail = ft_lstlast(ps->stack_a);
	if (min == ps->stack_a->rank && max == ft_lstlast(ps->stack_a)->rank)
	{
		sa(ps);
		rra(ps);
	}
	else if (min != ps->stack_a->rank && max == tail->rank)
		ra(ps);
	else if (min == ps->stack_a->rank && max != tail->rank)
		rra(ps);
	else if (max == ps->stack_a->rank && min != tail->rank)
		sa(ps);
	else if (max != ps->stack_a->rank && min == tail->rank)
	{
		sa(ps);
		ra(ps);
	}
}

void radix_sort(t_ps *ps)
{
	int max = get_max(ps->stack_a);
	unsigned int num_bits = 0;
	while (max >> num_bits != 0)
		++num_bits;
	unsigned int i = 0;
	unsigned int j = 0;
	while (i < num_bits)
	{
		j = 0;
		unsigned int size = ft_lstsize(ps->stack_a);
		while (j < size)
		{
			int value = ft_lstlast(ps->stack_a)->rank;
			if (((value >> i) & 1) == 0)
				pb(ps);
			else
				ra(ps);
			j++;
		}
		while (ps->stack_b)
			pa(ps);
		i++;
	}

}

void	push_swap(t_ps *ps)
{
	if (is_descending(ps->stack_a) == 0)
	{
		if (ps->size_a == 2)
			return (ra(ps));
		else if (ps->size_a == 3)
			return (sort_3(ps));
		else
			return (radix_sort(ps));
	}
}
