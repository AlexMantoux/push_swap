/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_transform.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:25 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/23 15:11:36 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rotate_a(t_list **stack_a)
{
    t_list  *last;
    t_list  *before_last;

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
    // write(1, "rra\n", 4);
}

void reverse_rotate_b(t_list **stack_b)
{
    t_list  *last;
    t_list  *before_last;

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
    // write(1, "rra\n", 4);
}

void    reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
    // write(1, "rrr\n", 4);
}