/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 12:28:23 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

int	rotate_a(t_list **stack_a, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	bench->ra++;
	ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	bench->rb++;
	ft_printf("rb\n");
	return (1);
}

int	rotate_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (!stack_a || !*stack_a)
		return (0);
	rotate_a(stack_a, bench);
	rotate_b(stack_b, bench);
	ft_printf("rr\n");
	return (1);
}
