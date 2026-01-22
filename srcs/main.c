/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:16 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 13:05:11 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	ft_lstdisplay(t_list **lst, char c)
{
	t_list	*current;

	current = *lst;
	ft_printf("\n");
	while (current != NULL)
	{
		ft_printf("%d-->", current->content);
		ft_printf("%d\n", current->index);
		current = current->next;
	}
	ft_printf("_\n");
	if (c == 'a')
		ft_printf("a\n");
	else
		ft_printf("b\n");
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_bench	bench;
	t_flags	flags;

	if (argc < 2)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	flags_init(&flags);
	init_bench(&bench);
	if (!complete_lst(argv, &lst_a, &flags))
		return (0);
	if (!compute_disorder(lst_a))
		return (0);
	normalize_indices(lst_a);
	flag_execution(flags, &lst_a, &lst_b, &bench);
	ft_lstdisplay(&lst_a, 'a');
	ft_lstdisplay(&lst_b, 'b');
	ft_printf("______________________________\n");
}
