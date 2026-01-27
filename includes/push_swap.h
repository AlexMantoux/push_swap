/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:51:33 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/27 14:21:02 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:42 by amantoux         #+#    #+#             */
/*   Updated: 2026/01/19 11:07:36 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

int		parse_flags(char	*ret, t_flags	*flags);

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

void	flag_execution(t_flags	flags, t_list	**lst_a, t_list	**lst_b,
			t_bench	*bench);

long	ft_atoi(const char *str);
int		ft_isdigit(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		complete_lst(char **argv, t_list	**lst_a, t_flags	*flags);

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdisplay(t_list **lst, char c);

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

float	compute_disorder(t_list *stack_a);
void	selection_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	adaptive_sort(double disorder, t_list **lst_a, t_list **lst_b,
			t_bench *bench);

void	chunk_based_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);

void	normalize_indices(t_list *stack);
void	hard_sort(t_list **lst_a, t_bench *bench);
void	radix_sort(t_list **lst_a, t_list **lst_b, t_bench *bench);

int		check_dooble_flags(char	*ret, t_flags	*flags);
void	flags_init(t_flags	*flags);

void	init_bench(t_bench *bench);
void	display_bench(t_bench *bench, double disorder);

#endif