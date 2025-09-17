/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:58:56 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 20:59:23 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char *_src;
	size_t len;

	_src = (char *)src;
	len = 0;
	if (size > 0)
	{
		while (len < size - 1 && *src)
		{
			*dst++ = *src++;
			len++;
		}
		*dst = 0;
	}
	len = ft_strlen(_src);
	return (len);
}
