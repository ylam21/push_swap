/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:07:36 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (validate_args(argc, argv) != 0)
		return (print_error(), 1);

	if (init_ps(&ps, argc, argv) != 0)
		return (print_error(), 1);

	push_swap(&ps);
	free_stack(ps.stack_a);
	return (0);
}
