/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:27 by alexmantoux       #+#    #+#             */
/*   Updated: 2026/01/13 11:13:56 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void    rotate_a(t_list **stack_a)
{
    t_list  *first;
    t_list  *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    *stack_a = first->next;
    first->next = NULL;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_printf("ra\n");
}

void rotate_b(t_list **stack_b)
{
    t_list  *first;
    t_list  *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    *stack_b = first->next;
    first->next = NULL;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_printf("rb\n");
}

void rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    ft_printf("rr\n");
}