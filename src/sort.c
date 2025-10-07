/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 19:08:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_ps *ps)
{
	unsigned int	head;
	unsigned int	tail;
	unsigned int	max;

	max = get_max(ps->lst_a);
	head = *(unsigned int *)ps->lst_a->content;
	tail = *(unsigned int *)ft_lstlast(ps->lst_a)->content;
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

int	get_target(t_ps *ps, int max)
{
	int		candidate;
	t_list	*curr;

	if (!ps->lst_a || !ps->lst_b)
		return (-1);
	candidate = *(int *)ft_lstlast(ps->lst_b)->content;
	if (candidate == max)
		return (0);
	while (candidate < max)
	{
		curr = ps->lst_a;
		while (curr)
		{
			if (*(int *)curr->content == candidate + 1)
				return (candidate + 1);
			curr = curr->next;
		}
		candidate++;
	}
	return (-1);
}

void	sort_small(t_ps *ps)
{
	int	target;
	int	size;
	int	max;

	size = ft_lstsize(ps->lst_a);
	max = get_max(ps->lst_a);
	if (size == 3)
		return (sort_3(ps));
	pb(ps);
	if (size == 5)
		pb(ps);
	sort_3(ps);
	while (ps->lst_b)
	{
		target = get_target(ps, max);
		move_to_tail_a(ps, target);
		pa(ps);
	}
	move_to_tail_a(ps, 0);
}

void	radix_sort(t_ps *ps)
{
	unsigned int	i;
	int				j;
	int				value;

	i = 0;
	j = 0;
	while (i < get_num_bits(get_max(ps->lst_a)))
	{
		j = 0;
		while (j < ft_lstsize(ps->lst_a))
		{
			value = *(int *)(ft_lstlast(ps->lst_a)->content);
			if (((value >> i) & 1) == 0)
				pb(ps);
			else
				ra(ps);
			j++;
		}
		while (ps->lst_b)
			pa(ps);
		i++;
	}
}

void	push_swap(t_ps *ps)
{
	int	size;

	size = ft_lstsize(ps->lst_a);
	if (size > 1 && is_descending(ps->lst_a) == 0)
	{
		if (size == 2)
			return (ra(ps));
		else if (size < 6)
			return (sort_small(ps));
		else
			return (radix_sort(ps));
	}
}
