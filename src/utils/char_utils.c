/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:46 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 21:36:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_zero(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
		i++;
	if (s[i] == '0' && s[i + 1] == '\0')
		return (1);
	return (0);
}

int	get_strv_len(char **strv)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (strv[i] != NULL)
	{
		i++;
		len++;
	}
	return (len);
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(const char *s)
{
	unsigned int	i;
	unsigned int	minus;
	int				ret;

	if (!s)
		return (0);
	i = 0;
	minus = 0;
	ret = 0;
	while (is_whitespace(s[i]))
		i++;
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			minus = 1;
		i++;
	}
	while (ft_isdigit(s[i]))
		ret = ret * 10 + (s[i++] - '0');
	if (minus)
		return (-ret);
	return (ret);
}
