/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 12:25:49 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bring_to_top(t_list **stack_a, int size_a)
{
	int	target_idx;
	int	distance;
	int	i;

	target_idx = get_target_index(stack_a, size_a);
	distance = distance_to_top(size_a, target_idx);
	i = 0;
	while (i < distance)
	{
		if (target_idx > (size_a - 1) / 2)
		{
			rotate(stack_a);
			printf("ra\n");
		}
		else
		{
			reverse_rotate(stack_a);
			printf("rra\n");
		}
		i++;
	}
}

void	fill_b(t_ps *ps)
{
	int	prev;
	int	min_num;
	int	curr;

	prev = ps->highest_a;
	while (ps->stack_a != NULL)
	{
		min_num = get_min(ps->stack_a);
		if (ft_lstsize(ps->stack_b) != 0)
			prev = ft_lstlast(ps->stack_b)->d;
		bring_to_top(&(ps->stack_a), ft_lstsize(ps->stack_a));
		push(&(ps->stack_a), &(ps->stack_b));
		printf("pb\n");
		curr = ft_lstlast(ps->stack_b)->d;
		if (curr != prev + 1 && curr != min_num && ft_lstsize(ps->stack_b) > 1)
		{
			rotate(&(ps->stack_b));
			printf("rb\n");
		}
	}
}

void	arrange_b(t_ps *ps)
{
	int	max_index;
	int	dist;
	int	i;

	if (is_ascending(ps->stack_b) == 0)
	{
		max_index = get_index(ps->stack_b, ps->highest_a);
		dist = (ps->size_a - 1) - max_index;
		i = 0;
		while (i < dist)
		{
			rotate(&(ps->stack_b));
			printf("rb\n");
			i++;
		}
	}
}

void	push_back_to_a(t_ps *ps)
{
	int	i;
	int	size_b;

	i = 0;
	size_b = ft_lstsize(ps->stack_b);
	while (i < size_b)
	{
		push(&(ps->stack_b), &(ps->stack_a));
		printf("pa\n");
		i++;
	}
}

void	push_swap(t_ps *ps)
{
	if (is_descending(ps->stack_a) == 0)
	{
		if (ft_lstsize(ps->stack_a) == 2)
		{
			rotate(&(ps->stack_a));
			printf("ra\n");
			return ;
		}
		fill_b(ps);
		arrange_b(ps);
		push_back_to_a(ps);
	}
}
