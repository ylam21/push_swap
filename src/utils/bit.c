/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:31:29 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 19:31:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_num_bits(unsigned int num)
{
	unsigned int	num_bits;

	num_bits = 0;
	while (num >> num_bits != 0)
		++num_bits;
	return (num_bits);
}
