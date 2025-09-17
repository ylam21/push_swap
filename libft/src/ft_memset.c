/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:14:31 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 21:14:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
