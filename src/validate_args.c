/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:48 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 21:00:11 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"






int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		_s[i] = c;
		i++;
	}
	return (s);
}


int	check_int(char *s, size_t s_len)
{
	if (!s)
		return (1);
	if (s_len > 11)
		return (2);
	else if (s_len == 10 && ft_strncmp(s, "2147483647", 10) != 0)
		return (3);
	else if (s_len == 11 && ft_strncmp(s, "-2147483648", 11) != 0)
		return (4);
	return (0);
}

unsigned int	get_param_count(char **params)
{
	size_t			count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (params && params[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

int	handle_one_param(char *s)
{
	char			**params;
	unsigned int	i;
	unsigned int	j;
	unsigned int	param_count;

	if (!s)
		return (1);
	params = ft_split(s, ' ');
	if (!params)
		return (2);
	param_count = get_param_count(params);
	i = 0;
	j = 0;
	while (i < param_count)
	{
		if (is_zero(params[i]) == 0 && ft_atoi(params[i]) == 0)
			return (1);
		j = i + 1;
		while (j < param_count)
		{
			if (ft_atoi(params[i]) == ft_atoi(params[j]))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	handle_more_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (is_zero(argv[i]) == 0 && ft_atoi(argv[i]) == 0)
			return (1);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (handle_one_param(argv[1]));
	else if (argc > 2)
		return (handle_more_param(argc, argv));
	return (0);
}
