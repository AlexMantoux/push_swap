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