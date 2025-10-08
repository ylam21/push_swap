/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:14 by omaly             #+#    #+#             */
/*   Updated: 2025/10/08 16:14:37 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "push_swap.h"

typedef struct s_ps	t_ps;
int					init_ps(t_ps *ps, int argc, char **argv);
unsigned int		*get_ranked_arr(int *arr, int size);
t_list				*tokens_to_lst(char **tokens, unsigned int offset);
#endif
