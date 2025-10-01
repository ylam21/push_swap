/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:00:24 by omaly             #+#    #+#             */
/*   Updated: 2025/10/01 13:25:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// Libft
# include "../libft/libft.h"
// Project modules
# include "error.h"
# include "init.h"
# include "ops.h"
# include "utils.h"
# include "validate.h"

typedef struct s_ps
{
	t_list			*stack_a;
	t_list			*stack_b;
	size_t			size_a;
	unsigned int	max_a;
}					t_ps;
void				push_swap(t_ps *ps);

#endif
