/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/10/01 13:36:10 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
	{
		return (1);
	}
	if (validate_args(argc, argv) != 0)
	{
		print_error(2);
		return (2);
	}
	if (init_ps(&ps, argc, argv) != 0)
	{
		print_error(2);
		return (3);
	}
	push_swap(&ps);
	free_ps(&ps);
	return (0);
}
