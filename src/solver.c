/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:55 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 21:32:32 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_bound_to_top(t_ps *ps)
{
	int	size;
	int	min;
	int	max;
	int	min_index;
	int	max_index;
	int	closer;
	int	counter;

	if (!ps->size_a)
		return ;
	size = ft_lstsize(ps->stack_a);
	min = get_minimum(ps->stack_a);
	max = get_maximum(ps->stack_a);
	min_index = get_index(ps->stack_a, min);
	max_index = get_index(ps->stack_a, max);
	closer = get_closer_index(min_index, max_index, size);
	counter = 0;
	while (counter < distance_to_top(size, closer))
	{
		if (closer > (size - 1) / 2)
		{
			rotate(&(ps->stack_a));
			printf("rotate %c\n", 'a');
		}
		else
		{
			reverse_rotate(&(ps->stack_a));
			printf("reverse rotate %c\n", 'a');
		}
		counter++;
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
		min_num = get_minimum(ps->stack_a);
		if (ft_lstsize(ps->stack_b) != 0)
			prev = ft_lstlast(ps->stack_b)->d;
		get_bound_to_top(ps);
		push(&(ps->stack_a), &(ps->stack_b));
		printf("pb\n");
		curr = ft_lstlast(ps->stack_b)->d;
		if (curr != prev + 1 && curr != min_num && ft_lstsize(ps->stack_b) > 1)
		{
			rotate(&(ps->stack_b));
			printf("rotate b\n");
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
			printf("rotate b\n");
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
			printf("rotate a\n");
			return;
		}
		fill_b(ps);
		arrange_b(ps);
		push_back_to_a(ps);
	}
}
