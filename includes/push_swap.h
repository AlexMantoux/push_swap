
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
        int            content;
        struct s_list   *next;
}               t_list;

int     ft_atoi(const char *str);
int     ft_lstsize(t_list *lst);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(int content);
t_list  *ft_lstlast(t_list *lst);
void	ft_lstdisplay(t_list **lst, char c);

#endif