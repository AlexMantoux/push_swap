/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:42 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/29 16:19:52 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_count_bench
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		adaptive;
	char	complexity;
}	t_bench;

size_t	ft_strlen_dup(const char *s);
int		ft_isdigit(const char *str);
int		error_check_digits(char **ret);
long	ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*big_str(char **argv);
char	**big_split(char const *str);
char	**ft_split(char const *s, char c);
int		find_in_lst(t_list *lst_a, int value);
int		complete_lst(char **argv, t_list	**lst_a, t_flags	*flags);

void	flags_init(t_flags	*flags);
int		parse_flags(char	*ret, t_flags	*flags);
void	flag_execution(t_flags	flags, t_list	**lst_a, t_list	**lst_b,
			t_bench	*bench);
int		check_dooble_flags(char	*ret, t_flags	*flags);

float	compute_disorder(t_list *stack_a);

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);

void	swap_a(t_list **lst_a, t_bench *bench);
void	swap_b(t_list **lst_b, t_bench *bench);
void	swap_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	push_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	push_b(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	rotate_a(t_list **stack_a, t_bench *bench);
void	rotate_b(t_list **stack_b, t_bench *bench);
void	rotate_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	reverse_rotate_a(t_list **stack_a, t_bench *bench);
void	reverse_rotate_b(t_list **stack_b, t_bench *bench);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench);

void	normalize_indices(t_list *stack);
void	hard_sort(t_list **lst_a, t_bench *bench, t_flags flags);

void	selection_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	chunk_based_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	radix_sort(t_list **lst_a, t_list **lst_b, t_bench *bench);
void	adaptive_sort(double disorder, t_list **lst_a, t_list **lst_b,
			t_bench *bench);

void	init_bench(t_bench *bench);
void	display_bench(t_bench *bench, double disorder);

void	free_tab(char **tab);

#endif