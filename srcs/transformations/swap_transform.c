/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:23 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/23 15:10:50 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_a(t_list **stack_a)
{
    t_list  *first;
    t_list  *second;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    // write(1, "sa\n", 3);
}

void swap_b(t_list **stack_b)
{
    t_list  *first;
    t_list  *second;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    // write(1, "sb\n", 3);
}

void swap_a_b(t_list **stack_a, t_list **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    // write(1, "ss\n", 3);
}