/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/15 15:33:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_ps(t_ps *ps, int argc, char **argv)
{
	ps->stack_a = parse(argc, argv);
	ps->stack_b = NULL;
	ps->size_a = ft_lstsize(ps->stack_a);
}
