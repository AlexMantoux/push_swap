/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:54:08 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/10 12:09:06 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float compute_disorder(t_list *stack_a)
{
	int	i;
	int	j;
    float	mistakes;
    float	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;

	// if (ft_lstsize(stack_a) < 3)
	// {
	// 	if (find_content_stack(stack_a, 0) > find_content_stack(stack_a, 1))
	// 			return (1);
	// 	else
	// 		return (0);
	// }
	
	while (i < ft_lstsize(stack_a))
	{
		j = i + 1;
		while (j < ft_lstsize(stack_a))
		{
			total_pairs += 1;
			if (find_content_stack(stack_a, i) > find_content_stack(stack_a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	find_content_stack(t_list *stack, int n)
{
	int	i;

	i = 0;
	if (n > ft_lstsize(stack))
		return (0);
	while (i < n)
	{
		stack=stack->next;
		i++;
	}
	return (stack->content);
}