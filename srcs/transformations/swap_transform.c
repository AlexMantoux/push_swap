/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:23 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/11 09:47:28 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_a(t_list **lst_a)
{
    t_list *tmp;

    tmp = *lst_a;
    if (!(*lst_a)->next)
        return ;
    *lst_a = (*lst_a)->next;
    (*lst_a)->next = tmp;
}

void swap_b(t_list **lst_b)
{
    t_list *tmp;

    tmp = *lst_b;
    if (!(*lst_b)->next)
        return ;
    *lst_b = (*lst_b)->next;
    (*lst_b)->next = tmp;
}

void swap_a_b(t_list **lst_a_b)
{
    return ;
}