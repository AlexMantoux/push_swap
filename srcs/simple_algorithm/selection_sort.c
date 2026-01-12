/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:15:21 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/12 16:14:16 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	selection_sort(t_list **stack_a, t_list **stack_b)
{
	int     i;
	int     j;
	int     min_index;
	int     size;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (find_content_stack(*stack_a, j) < find_content_stack(*stack_a, min_index))
				min_index = j;
			j++;
		}
		while (min_index > 0)
		{
			rotate_a(stack_a);
			min_index--;
		}
		push_b(stack_a, stack_b);
		size--;
		i++;
	}
	while (ft_lstsize(*stack_b) > 0)
		push_a(stack_a, stack_b);
	return (0);
}
