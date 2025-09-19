/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 15:02:37 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_ps *ps)
{
	t_list	*tail;

	tail = ft_lstlast(ps->stack_a);
	if (0 == *(unsigned int *)(ps->stack_a->content)
		&& ps->max_a == *(unsigned int *)(ft_lstlast(ps->stack_a)->content))
	{
		sa(ps);
		rra(ps);
	}
	else if (0 != *(unsigned int *)ps->stack_a->content
		&& ps->max_a == *(unsigned int *)tail->content)
		ra(ps);
	else if (0 == *(unsigned int *)ps->stack_a->content
		&& ps->max_a != *(unsigned int *)tail->content)
		rra(ps);
	else if (ps->max_a == *(unsigned int *)ps->stack_a->content
		&& 0 != *(unsigned int *)tail->content)
		sa(ps);
	else if (ps->max_a != *(unsigned int *)ps->stack_a->content
		&& 0 == *(unsigned int *)tail->content)
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
		else
			return (radix_sort(ps));
	}
}
