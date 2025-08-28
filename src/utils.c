#include "../includes/utils.h"
#include "../includes/list.h"

int ft_lstsize(t_list *lst)
{
	int size = 0;
	if (!lst)
		return size;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return size;
}

t_list *ft_lstnew(int d)
{
	t_list *lst = malloc(sizeof(t_list));
	if (!lst)
		return NULL;
	lst->d = d;
	lst->next = NULL;
	return lst;
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return NULL;
	while (lst->next)
		lst = lst->next;
	return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!lst || !*lst)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}

	last = ft_lstlast(*lst);
	last->next = new;
}
int is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int is_sign(char c)
{
	return (c == '-' || c == '+');
}

int is_whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

int ft_atoi(const char *s)
{
	if (!s)
		return 0;
	unsigned int i = 0;
	unsigned int minus = 0;
	int ret = 0;
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
	{
		if (s[i] == '-')
			minus = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (is_digit(s[i]) == 0)
			return 0;
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	if (minus)
		return -ret;
	return ret;
}

int is_zero(const char *s)
{
	if (!s)
		return 0;
	unsigned int i = 0;
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
		i++;
	if (s[i] == '0' && s[i + 1] == '\0')
		return 1;
	return 0;
}
