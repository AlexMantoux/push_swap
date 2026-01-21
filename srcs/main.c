/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:16 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/19 12:45:58 by amantoux         ###   ########.fr       */
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

void	init_bench(t_bench *bench)
{
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	display_bench(t_bench *bench)
{
	ft_printf("pa = %d     ", bench->pa);
	ft_printf("pa = %d\n", bench->pb);
	ft_printf("sa = %d     ", bench->sa);
	ft_printf("sb = %d\n", bench->sb);
	ft_printf("ra = %d     ", bench->ra);
	ft_printf("rb = %d     ", bench->rb);
	ft_printf("rr = %d\n", bench->rr);
	ft_printf("ra = %d     ", bench->rra);
	ft_printf("rb = %d     ", bench->rrb);
	ft_printf("rrr = %d\n", bench->rrr);
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
