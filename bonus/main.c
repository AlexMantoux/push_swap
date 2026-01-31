/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:54:41 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/31 06:41:53 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "gnl/get_next_line.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	apply_op(t_list **lst_a, t_list **lst_b, char *line, t_bench bench)
{
	if (ft_strcmp("sa\n", line) == 0)
		swap_a(lst_a, &bench, 0);
	else if (ft_strcmp("sb\n", line) == 0)
		swap_b(lst_b, &bench, 0);
	else if (ft_strcmp("ss\n", line) == 0)
		swap_a_b(lst_a, lst_b, &bench, 0);
	else if (ft_strcmp("pa\n", line) == 0)
		push_a(lst_a, lst_b, &bench, 0);
	else if (ft_strcmp("pb\n", line) == 0)
		push_b(lst_a, lst_b, &bench, 0);
	else if (ft_strcmp("ra\n", line) == 0)
		rotate_a(lst_a, &bench, 0);
	else if (ft_strcmp("rb\n", line) == 0)
		rotate_b(lst_b, &bench, 0);
	else if (ft_strcmp("rr\n", line) == 0)
		rotate_a_b(lst_a, lst_b, &bench, 0);
	else if (ft_strcmp("rra\n", line) == 0)
		reverse_rotate_a(lst_a, &bench, 0);
	else if (ft_strcmp("rrb\n", line) == 0)
		reverse_rotate_b(lst_b, &bench, 0);
	else if (ft_strcmp("rrr\n", line) == 0)
		reverse_rotate_a_b(lst_a, lst_b, &bench, 0);
}

static int	final_check(t_list *lst_a, t_list *lst_b)
{
	if (lst_b != NULL)
		return (0);
	while (lst_a != NULL)
	{
		if (lst_a->next != NULL)
		{
			if (lst_a->content > lst_a->next->content)
				return (0);
		}
		lst_a = lst_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags	flags;
	t_bench	bench;
	char	*line;

	init_bench(&bench);
	if (argc < 2)
		return (1);
	lst_a = NULL;
	lst_b = NULL;
	flags_init(&flags);
	if (!complete_lst(argv, &lst_a, &flags))
		return (1);
	line = get_next_line(0);
	while (line != NULL)
	{
		apply_op(&lst_a, &lst_b, line, bench);
		free(line);
		line = get_next_line(0);
	}
	if (final_check(lst_a, lst_b) == 1)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
}
