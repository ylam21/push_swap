/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:48 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 16:20:33 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
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
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
	{
		if (s[i] == '-')
			minus = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (is_digit(s[i]) == 0)
			return (0);
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	if (minus)
		return (-ret);
	return (ret);
}

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
