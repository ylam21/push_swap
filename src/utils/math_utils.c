/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:31:07 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 10:34:44 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	distance_to_top(int size, int index)
{
	int	middle;

	if (index < 0 || size < 0)
		return (-1);
	if (index == size - 1)
		return (0);
	middle = (size - 1) / 2;
	if (index >= middle)
		return (size - 1 - index);
	else
		return (index + 1);
}
