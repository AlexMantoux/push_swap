/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:39:27 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 10:27:02 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <math.h>

static int	ft_sqrt(int x)
{
	int	i;

	i = 0;
	if (x < 0)
		return (-1);
	if (x == 0)
		return (0);
	while (i * i < x)
		i++;
	if (i * i == x)
		return (i);
	return (i - 1);
}

static int	chunk_size(int size)
{
	int	sqrt_val;

	sqrt_val = ft_sqrt(size);
	if (size <= 100)
		return (sqrt_val * 2);
	return ((sqrt_val * 2) + 10);
}

static void	move_to_top_b(t_list **stack_b, int pos)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_b(stack_b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_b(stack_b);
			pos++;
		}
	}
}

static int	find_max_index_pos(t_list *stack)
{
	int	max_index;
	int	max_pos;
	int	pos;

	if (!stack)
		return (-1);
	max_index = stack->index;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

void	chunk_based_sort(t_list **stack_a, t_list **stack_b)
{
	int i = 0;
	int range = chunk_size(ft_lstsize(*stack_a));

	while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            push_b(stack_a, stack_b);
            rotate_b(stack_b);
            i++;
        }
        else if ((*stack_a)->index <= i + range)
        {
            push_b(stack_a, stack_b);
            i++;
        }
        else
            rotate_a(stack_a);
    }
	while (*stack_b)
	{
    	int max_pos = find_max_index_pos(*stack_b);
    	move_to_top_b(stack_b, max_pos);
    	push_a(stack_a, stack_b);
    }
}