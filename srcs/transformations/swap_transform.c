/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:23 by alexmantoux       #+#    #+#             */
/*   Updated: 2026/01/13 11:14:19 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
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
    ft_printf("sa\n");
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
    ft_printf("sb\n");
}

void swap_a_b(t_list **stack_a, t_list **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    ft_printf("ss\n");
}