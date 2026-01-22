/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:15:21 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 14:54:31 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_pos(t_list *stack)
{
	int	min_val;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (-1);
	min_val = stack->content;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->content < min_val)
		{
			min_val = stack->content;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

void	selection_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;
	int	min_pos;

	while (ft_lstsize(*stack_a) > 0)
	{
		size = ft_lstsize(*stack_a);
		min_pos = find_min_pos(*stack_a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				rotate_a(stack_a, bench);
		}
		else
		{
			while (min_pos++ < size)
				reverse_rotate_a(stack_a, bench);
		}
		push_b(stack_a, stack_b, bench);
	}
	while (*stack_b)
		push_a(stack_a, stack_b, bench);
	bench->complexity = 's';
}
