/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/31 06:40:23 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	rotate_a(t_list **stack_a, t_bench *bench, int print)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	bench->ra++;
	if (print)
		ft_printf(1, "ra\n");
}

void	rotate_b(t_list **stack_b, t_bench *bench, int print)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	bench->rb++;
	if (print)
		ft_printf(1, "rb\n");
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b, t_bench *bench, int print)
{
	if (!stack_a || !*stack_a)
		return ;
	rotate_a(stack_a, bench, 1);
	rotate_b(stack_b, bench, 1);
	if (print)
		ft_printf(1, "rr\n");
}
