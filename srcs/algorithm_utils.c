/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:23 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/19 12:33:27 by amantoux         ###   ########.fr       */
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

void	hard_sort(t_list **lst_a, t_bench *bench)
{
	if (ft_lstsize(*lst_a) == 2)
		swap_a(lst_a, bench);
	else
		sort_hard(lst_a, bench);
}
