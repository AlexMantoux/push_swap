/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 12:26:27 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

int	push_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	bench->pa++;
	ft_printf("pa\n");
	return (1);
}

int	push_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	bench->pb++;
	ft_printf("pb\n");
	return (1);
}
