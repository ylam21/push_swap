/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 21:25:26 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_ps *ps)
{
	int		min;
	int		max;
	t_list	*tail;

	min = get_min(ps->stack_a);
	max = get_max(ps->stack_a);
	tail = ft_lstlast(ps->stack_a);
	if (min == ps->stack_a->content && max == ft_lstlast(ps->stack_a)->content)
	{
		sa(ps);
		rra(ps);
	}
	else if (min != ps->stack_a->content && max == tail->content)
		ra(ps);
	else if (min == ps->stack_a->content && max != tail->content)
		rra(ps);
	else if (max == ps->stack_a->content && min != tail->content)
		sa(ps);
	else if (max != ps->stack_a->content && min == tail->content)
	{
		sa(ps);
		ra(ps);
	}
}

unsigned int	get_num_bits(unsigned int num)
{
	unsigned int	num_bits;

	num_bits = 0;
	while (num >> num_bits != 0)
		++num_bits;
	return (num_bits);
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
			value = ft_lstlast(ps->stack_a)->content;
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
