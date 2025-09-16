/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:24:23 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	init_ps(t_ps *ps, int argc, char **argv)
{
	int *raw;
	unsigned int *ranked;

	raw = parse_args(argc, argv);
	if (!raw)
		return 1;
	ranked = get_ranked_arr(raw, argc - 1);
	if (!ranked){
		free(raw);
		return 2;
	}
	ps->stack_a = build_stack(ranked, argc - 1);
	if (!ps->stack_a) {
		free(raw);
		free(ranked);
		return 3;
	}
	ps->stack_b = NULL;
	ps->size_a = ft_lstsize(ps->stack_a);
	free(raw);
	free(ranked);
	return 0;
}
