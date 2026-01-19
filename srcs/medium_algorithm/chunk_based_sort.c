/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:39:27 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/19 12:22:12 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <math.h>

int ft_sqrt(int x)
{
	int i;

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

int	chunk_size(int size)
{
	int	sqrt_val;

	sqrt_val = ft_sqrt(size);
	if (size <= 100)
		return (sqrt_val * 2);
	return ((sqrt_val * 2) + 10);
}

int	chunk_based_sort(t_list **stack_a, t_list **stack_b)
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
}