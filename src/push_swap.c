/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 12:19:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (validate_args(argc, argv) != 0)
		return (write(2, "Error\n", 6), 1);
	init_ps(&ps, argc, argv);
	push_swap(&ps);
	// print_stack(ps.stack_a);
	free_stack(ps.stack_a);
	return (0);
}
