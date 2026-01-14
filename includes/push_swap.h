/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:42 by alexmantoux       #+#    #+#             */
/*   Updated: 2026/01/14 08:36:49 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_flags {
    int simple;
    int medium;
    int complex;
    int bench;
}   t_flags;

void parse_flags(int argc, char **argv, t_flags *flags);

typedef struct s_list
{
        int            content;
        struct s_list   *next;
}               t_list;

long	ft_atoi(const char *str);
int	ft_isdigit(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int	complete_lst(char **argv, t_list  **lst_a);

int     ft_lstsize(t_list *lst);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(int content);
t_list  *ft_lstlast(t_list *lst);
void	ft_lstdisplay(t_list **lst, char c);
void    swap_a(t_list **lst_a);
void    swap_b(t_list **lst_b);
void    swap_a_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_a, t_list **stack_b);
void    push_b(t_list **stack_a, t_list **stack_b);
void    rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void    rotate_a_b(t_list **stack_a, t_list **stack_b);
void    reverse_rotate_a(t_list **stack_a);
void    reverse_rotate_b(t_list **stack_b);
void    reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);
int	find_content_stack(t_list *stack, int n);
float   compute_disorder(t_list *stack_a);
void    selection_sort(t_list **stack_a, t_list **stack_b);


#endif