/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:14:59 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 16:15:18 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	distance_to_top(int size, int index)
{
	int	middle;

	if (index < 0 || size < 0)
		return (-1);
	if (index == size - 1)
		return (0);
	middle = (size - 1) / 2;
	if (index >= middle)
		return (size - index);
	else
		return (index + 1);
}

// void	print_stack(t_list *stack)
// {
// 	t_list	*curr;

// 	if (!stack)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	curr = stack;
// 	while (curr)
// 	{
// 		printf("%d ", curr->d);
// 		curr = curr->next;
// 	}
// 	printf("\n");
// }

int	get_minimum(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = curr->d;
	while (curr)
	{
		if (curr->d < min)
			min = curr->d;
		curr = curr->next;
	}
	return (min);
}

int	get_maximum(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = curr->d;
	while (curr)
	{
		if (curr->d > max)
			max = curr->d;
		curr = curr->next;
	}
	return (max);
}
int	get_closer_index(int index_a, int index_b, int size)
{
	int	dist_a;
	int	dist_b;

	if (index_a < 0 || index_b < 0 || size < 0)
		return (-1);
	dist_a = distance_to_top(size, index_a);
	dist_b = distance_to_top(size, index_b);
	if (dist_a <= dist_b)
		return (index_a);
	else
		return (index_b);
}
