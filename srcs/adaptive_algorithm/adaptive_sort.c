/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:46:36 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/14 09:56:49 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	adaptive_sort(double disorder)
{
    ft_printf("%f\n", disorder);
    if (disorder < 0.2)
    {
        ft_printf("simple algo");
    }
    else if (disorder >= 0.2 && disorder <= 0.5)
    {
        ft_printf("Medium algo");
    }
    else
    {
        ft_printf("Complex algo");
    }
}