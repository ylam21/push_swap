/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:00:24 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 16:51:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct s_ps
{
	t_list			*stack_a;
	t_list			*stack_b;
	unsigned int	size_a;
}					t_ps;
int *parse_args(int argc, char **argv);
void print_arr(const int *arr, size_t size);
void print_error(void);
unsigned int *normalize(int *arr, size_t size);
// Main
void				push_swap(t_ps *ps);
int				init_ps(t_ps *ps, int argc, char **argv);
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
// Parsing and validation
t_list				*build_stack(unsigned int *arr, size_t size);
int					validate_args(int argc, char **argv);
// Debug
void				print_stack(t_list *stack);
// Utilities for operations on t_list
t_list				*ft_lstnew(int d);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newlst);
unsigned int		ft_lstsize(t_list *lst);
void				free_stack(t_list *stack);
int					is_ascending(t_list *lst);
int					is_descending(t_list *lst);
int					get_index(t_list *lst, int find);
int					get_max(t_list *stack);
int					get_min(t_list *stack);
int					get_target_index(t_list **stack_a, int size_a);
// Other Utilities
int					ft_atoi(const char *s);
int					get_closer_index(int index_a, int index_b, int size);
int					distance_to_top(int size, int index);
int					is_digit(int c);
int					is_sign(char c);
int					is_whitespace(char c);
#endif
