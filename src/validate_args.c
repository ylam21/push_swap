/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:48 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:35:11 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (is_zero(argv[i]) == 0 && ft_atoi(argv[i]) == 0)
			return (2);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}
