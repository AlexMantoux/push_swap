/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:23 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/27 14:43:07 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	normalize_indices(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->content < current->content)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

static void	sort_hard(t_list **lst_a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*lst_a)->content;
	second = (*lst_a)->next->content;
	third = (*lst_a)->next->next->content;
	if (first > second && second < third && third < first)
		rotate_a(lst_a, bench);
	if (first > second && second > third && third < first)
	{
		swap_a(lst_a, bench);
		reverse_rotate_a(lst_a, bench);
	}
	if (first > second && second < third && third > first)
		swap_a(lst_a, bench);
	if (first < second && second > third && third > first)
	{
		reverse_rotate_a(lst_a, bench);
		swap_a(lst_a, bench);
	}
	if (first < second && second > third && third < first)
		reverse_rotate_a(lst_a, bench);
}

void	hard_sort(t_list **lst_a, t_bench *bench, t_flags flags)
{
	if (flags.simple)
		bench->complexity = 's';
	if (flags.medium)
		bench->complexity = 'm';
	if (flags.complex)
		bench->complexity = 'c';
	if (!(flags.simple || flags.medium || flags.complex))
	{
		bench->adaptive = 1;
		bench->complexity = 's';
	}

	if (ft_lstsize(*lst_a) == 2)
		swap_a(lst_a, bench);
	else
		sort_hard(lst_a, bench);
}
