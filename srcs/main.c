/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:16 by rtrutall          #+#    #+#             */
/*   Updated: 2026/02/03 10:29:50 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	push_swap(t_list *lst_a, t_list *lst_b,
	t_bench bench, t_flags flags)
{
	float	disorder;

	disorder = compute_disorder(lst_a);
	normalize_indices(lst_a);
	if (ft_lstsize(lst_a) <= 3)
		hard_sort(&lst_a, &bench, flags);
	else
		flag_execution(flags, &lst_a, &lst_b, &bench);
	if (flags.bench)
		display_bench(&bench, disorder);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_bench	bench;
	t_flags	flags;
	float	disorder;

	if (argc < 3)
		return (1);
	lst_a = NULL;
	lst_b = NULL;
	flags_init(&flags);
	init_bench(&bench);
	if (!complete_lst(argv, &lst_a, &flags))
		return (1);
	disorder = compute_disorder(lst_a);
	if (disorder == 0 && !flags.bench)
	{
		ft_lstclear(&lst_a);
		return (1);
	}
	push_swap(lst_a, lst_b, bench, flags);
	return (0);
}
