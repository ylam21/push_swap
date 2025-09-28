/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:00:24 by omaly             #+#    #+#             */
/*   Updated: 2025/09/28 19:19:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	t_list			*stack_a;
	t_list			*stack_b;
	size_t			size_a;
	unsigned int	max_a;
}					t_ps;
void				push_swap(t_ps *ps);
// init_ps
int					init_ps(t_ps *ps, int argc, char **argv);
t_list				*tokens_to_lst(char **tokens, unsigned int offset);
unsigned int		*get_ranked_arr(int *arr, size_t size);
// Error
void				print_error(int fd);
// Operations
void				pa(t_ps *ps);
void				pb(t_ps *ps);
void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);
void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);
void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);
// Validation
int					validate_args(int argc, char **argv);
// Free
void				free_split(char **split);
void				free_ps(t_ps *ps);
// Utilities
int					ps_atoi(const char *s, int *out);
int					is_descending(t_list *lst);
int					get_max(t_list *stack);
void				print_stack(t_list *stack);
int					get_target_pos(t_list *lst, unsigned int target);
unsigned int		get_num_bits(unsigned int num);
int					is_sign(char c);
int					is_whitespace(char c);
#endif
