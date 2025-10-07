/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:00:24 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:16:05 by omaly            ###   ########.fr       */
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
	t_list			*lst_a;
	t_list			*lst_b;
}					t_ps;
void				push_swap(t_ps *ps);

#endif
