/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/28 19:17:35 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_ps *ps)
{
	unsigned int	head;
	unsigned int	tail;
	unsigned int	max;

	max = get_max(ps->stack_a);
	head = *(unsigned int *)ps->stack_a->content;
	tail = *(unsigned int *)ft_lstlast(ps->stack_a)->content;
	if (0 == head && max == tail)
	{
		sa(ps);
		rra(ps);
	}
	else if (0 != head && max == tail)
		ra(ps);
	else if (0 == head && max != tail)
		rra(ps);
	else if (max == head && 0 != tail)
		sa(ps);
	else if (max != head && 0 == tail)
	{
		sa(ps);
		ra(ps);
	}
}

void	arrange_a_for_candidate(t_ps *ps, unsigned int candidate)
{
	unsigned int	target;
	int				pos;

	target = candidate + 1;
	if (candidate == ps->max_a)
		target = 0;
	pos = get_target_pos(ps->stack_a, target);
	if (pos < ft_lstsize(ps->stack_a) / 2)
	{
		while (pos >= 0)
		{
			rra(ps);
			pos--;
		}
		return ;
	}
	else
	{
		while (pos < ft_lstsize(ps->stack_a) - 1)
		{
			ra(ps);
			pos++;
		}
		return ;
	}
}

void	sort_5(t_ps *ps)
{
	unsigned int	candidate;

	pb(ps);
	pb(ps);
	sort_3(ps);
	while (ps->stack_b)
	{
		candidate = *(unsigned int *)ft_lstlast(ps->stack_b)->content;
		arrange_a_for_candidate(ps, candidate);
		pa(ps);
	}
	arrange_a_for_candidate(ps, 4);
}

void	radix_sort(t_ps *ps)
{
	unsigned int	i;
	unsigned int	j;
	int				value;

	i = 0;
	j = 0;
	while (i < get_num_bits(ps->max_a))
	{
		j = 0;
		while (j < ps->size_a)
		{
			value = *(int *)(ft_lstlast(ps->stack_a)->content);
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
		else if (ps->size_a == 5)
			return (sort_5(ps));
		else
			return (radix_sort(ps));
	}
}
