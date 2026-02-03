/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:54:41 by amantoux          #+#    #+#             */
/*   Updated: 2026/02/03 13:13:20 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "gnl/get_next_line.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	error_quit(void)
{
	ft_printf(2, "Error\n");
	exit(1);
}

static void	apply_op(t_list **lst_a, t_list **lst_b, char *line, t_bench bench)
{
	if (ft_strcmp("sa\n", line) == 0)
		swap_a(lst_a, &bench);
	else if (ft_strcmp("sb\n", line) == 0)
		swap_b(lst_b, &bench);
	else if (ft_strcmp("ss\n", line) == 0)
		swap_a_b(lst_a, lst_b, &bench);
	else if (ft_strcmp("pa\n", line) == 0)
		push_a(lst_a, lst_b, &bench);
	else if (ft_strcmp("pb\n", line) == 0)
		push_b(lst_a, lst_b, &bench);
	else if (ft_strcmp("ra\n", line) == 0)
		rotate_a(lst_a, &bench);
	else if (ft_strcmp("rb\n", line) == 0)
		rotate_b(lst_b, &bench);
	else if (ft_strcmp("rr\n", line) == 0)
		rotate_a_b(lst_a, lst_b, &bench);
	else if (ft_strcmp("rra\n", line) == 0)
		reverse_rotate_a(lst_a, &bench);
	else if (ft_strcmp("rrb\n", line) == 0)
		reverse_rotate_b(lst_b, &bench);
	else if (ft_strcmp("rrr\n", line) == 0)
		reverse_rotate_a_b(lst_a, lst_b, &bench);
	else
		error_quit();
}

static int	final_check(t_list *lst_a, t_list *lst_b)
{
	if (lst_b != NULL)
	{
		ft_printf(1, "KO\n");
		return (1);
	}
	while (lst_a != NULL)
	{
		if (lst_a->next != NULL)
		{
			if (lst_a->content > lst_a->next->content)
			{
				ft_printf(1, "KO\n");
				return (1);
			}
		}
		lst_a = lst_a->next;
	}
	ft_printf(1, "OK\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags	flags;
	t_bench	bench;
	char	*line;

	init_bench(&bench);
	bench.silent = 1;
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
	return (final_check(lst_a, lst_b));
}
