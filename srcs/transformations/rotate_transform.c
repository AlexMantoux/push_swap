/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/08/22 23:45:49 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	rotate_a(t_list **stack_a, t_bench *bench)
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
	if (!(bench->silent))
		ft_printf(1, "ra\n");
}

void	rotate_b(t_list **stack_b, t_bench *bench)
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
	if (!(bench->silent))
		ft_printf(1, "rb\n");
}

static void	rotate_a_bis(t_list **stack_a)
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
}

static void	rotate_b_bis(t_list **stack_b)
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
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b,
			t_bench *bench)
{
	if (!stack_a || !*stack_a)
		return ;
	rotate_a_bis(stack_a);
	rotate_b_bis(stack_b);
	bench->rr++;
	if (!(bench->silent))
		ft_printf(1, "rr\n");
}
