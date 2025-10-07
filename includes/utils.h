/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:09:38 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:36:11 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "push_swap.h"

int				is_descending(t_list *lst);
int				get_max(t_list *lst);
int				get_target_pos(t_list *lst, int target);
unsigned int	get_num_bits(unsigned int num);
int				is_sign(char c);
int				is_whitespace(char c);
int				ps_atoi(const char *s, int *out);
void			free_split(char **split);
void			free_ps(t_ps *ps);
void			move_to_tail_a(t_ps *ps, int target);
#endif
