/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:21 by alexmantoux       #+#    #+#             */
/*   Updated: 2026/01/13 11:14:29 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void push_a(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;
    
    if (!stack_b || !*stack_b)
        return ;  
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    ft_printf("pa\n");
}

void push_b(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;
    
    if (!stack_a || !*stack_a)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    ft_printf("pb\n");
}
