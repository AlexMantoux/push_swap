/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:21 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/23 12:09:27 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    // write(1, "pa\n", 3);
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
    // write(1, "pb\n", 3);
}

void push_a_b(t_list **stack_a, t_list **stack_b)
{
    return ;
}