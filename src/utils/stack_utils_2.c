/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:47 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 11:18:01 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_target_index(t_list **stack_a, int size_a)
{
	int	min_idx;
	int	max_idx;

	min_idx = get_index(*stack_a, get_min(*stack_a));
	max_idx = get_index(*stack_a, get_max(*stack_a));
	return (get_closer_index(min_idx, max_idx, size_a));
}
