/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_transform.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/15 16:10:22 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

int	reverse_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	before_last = NULL;
	last = *stack_a;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
	return (1);
}

int	reverse_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	before_last = NULL;
	last = *stack_b;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
	return (1);
}

int	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
	return (1);
}
