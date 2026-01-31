/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/31 06:41:05 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	swap_a(t_list **stack_a, t_bench *bench, int print)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	bench->sa++;
	if (print)
		ft_printf(1, "sa\n");
}

void	swap_b(t_list **stack_b, t_bench *bench, int print)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	bench->sb++;
	if (print)
		ft_printf(1, "sb\n");
}

void	swap_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench, int print)
{
	swap_a(stack_a, bench, 1);
	swap_b(stack_b, bench, 1);
	if (print)
		ft_printf(1, "ss\n");
}
