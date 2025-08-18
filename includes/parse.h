#ifndef PARSE_H
#define PARSE_H

typedef struct s_list
{
	int d;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(int d);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *parse(int argc, char **argv);
#endif
