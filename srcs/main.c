/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:16 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 15:10:27 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	ft_lstdisplay(t_list **lst, char c)
{
	t_list	*current;

	current = *lst;
	ft_printf(1, "\n");
	while (current != NULL)
	{
		ft_printf(1, "%d-->", current->content);
		ft_printf(1, "%d\n", current->index);
		current = current->next;
	}
	ft_printf(1, "_\n");
	if (c == 'a')
		ft_printf(1, "a\n");
	else
		ft_printf(1, "b\n");
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_bench	bench;
	t_flags	flags;
	float	disorder;
	
	if (argc < 2)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	flags_init(&flags);
	init_bench(&bench);
	if (!complete_lst(argv, &lst_a, &flags))
		return (0);
	disorder = compute_disorder(lst_a);
	if (disorder == 0)
		return (0);
	normalize_indices(lst_a);
	flag_execution(flags, &lst_a, &lst_b, &bench);
	ft_lstdisplay(&lst_a, 'a');
	ft_lstdisplay(&lst_b, 'b');
	if (flags.bench)
		display_bench(&bench, disorder);
}
