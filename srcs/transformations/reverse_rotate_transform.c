/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_transform.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:34 by rtrutall          #+#    #+#             */
/*   Updated: 2026/08/22 23:45:45 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_list **stack_a, t_bench *bench)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
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
	bench->rra++;
	if (!(bench->silent))
		ft_printf(1, "rra\n");
}

void	reverse_rotate_b(t_list **stack_b, t_bench *bench)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
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
	bench->rrb++;
	if (!(bench->silent))
		ft_printf(1, "rrb\n");
}

static void	reverse_rotate_a_bis(t_list **stack_a)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
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
}

static void	reverse_rotate_b_bis(t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
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
}

void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b,
			t_bench *bench)
{
	if (!stack_b || !*stack_b)
		return ;
	reverse_rotate_a_bis(stack_a);
	reverse_rotate_b_bis(stack_b);
	bench->rrr++;
	if (!(bench->silent))
		ft_printf(1, "rrr\n");
}
