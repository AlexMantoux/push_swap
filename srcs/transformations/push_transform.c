/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/08/22 23:45:43 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	bench->pa++;
	if (!(bench->silent))
		ft_printf(1, "pa\n", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	bench->pb++;
	if (!(bench->silent))
		ft_printf(1, "pb\n");
}
