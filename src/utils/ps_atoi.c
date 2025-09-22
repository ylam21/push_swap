/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:46 by omaly             #+#    #+#             */
/*   Updated: 2025/09/22 17:36:42 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_out_of_bounds(long n, unsigned int sign)
{
	if (sign)
		n = n * -1;
	return (n > INT_MAX || n < INT_MIN);
}

int	is_negative(const char *s, unsigned int *i)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			(*i)++;
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int	accumulate_number(const char *s, unsigned int i, long *ret, int sign)
{
	while (ft_isdigit(s[i]))
	{
		*ret = *ret * 10 + (s[i++] - '0');
		if (is_out_of_bounds(*ret, sign))
			return (1);
	}
	return (0);
}

int	ps_atoi(const char *s, int *out)
{
	unsigned int	i;
	unsigned int	minus;
	long			ret;

	if (!s || !out)
		return (1);
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	minus = is_negative(s, &i);
	ret = 0;
	if (ft_isdigit(s[i]) == 0)
		return (2);
	if (accumulate_number(s, i, &ret, minus))
		return (3);
	if (minus)
		ret = -ret;
	*out = (int)ret;
	return (0);
}
