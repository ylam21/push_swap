/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:57:07 by omaly             #+#    #+#             */
/*   Updated: 2025/10/01 13:32:35 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_arr(int *arr, int size)
{
	int	i;
	int	tmp;

	if (!arr)
		return ;
	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
		i++;
	}
}

int	count_tokens(char **tokens)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	*tokens_to_arr(char **tokens, int count, unsigned int offset)
{
	int				*arr;
	unsigned int	i;
	int				n;

	if (!tokens)
		return (NULL);
	arr = malloc(sizeof(int) * (count - offset));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count - offset)
	{
		if (ps_atoi(tokens[i + offset], &n) != 0)
			return (NULL);
		arr[i] = n;
		i++;
	}
	return (arr);
}

t_list	*arr_to_lst(unsigned int *arr, int size)
{
	int				i;
	unsigned int	*rank;
	t_list			*lst;
	t_list			*new;

	if (!arr)
		return (NULL);
	lst = NULL;
	i = 0;
	while (i < size)
	{
		rank = malloc(sizeof(unsigned int));
		if (!rank)
			return (NULL);
		*rank = arr[i];
		new = ft_lstnew(rank);
		if (!new)
			return (NULL);
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

t_list	*tokens_to_lst(char **tokens, unsigned int offset)
{
	t_list			*lst;
	int				*raw;
	unsigned int	*ranked;
	int				count;

	count = count_tokens(tokens);
	raw = tokens_to_arr(tokens, count, offset);
	reverse_arr(raw, count - offset);
	if (!raw)
		return (NULL);
	ranked = get_ranked_arr(raw, count - offset);
	if (!ranked)
	{
		free(raw);
		return (NULL);
	}
	lst = arr_to_lst(ranked, count - offset);
	free(raw);
	free(ranked);
	return (lst);
}
