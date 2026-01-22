/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:46:36 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 11:40:21 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

void	adaptive_sort(double disorder, t_list **lst_a, t_list **lst_b,
						t_bench *bench)
{
	if (disorder < 0.2)
		selection_sort(lst_a, lst_b, bench);
	else if (disorder >= 0.2 && disorder <= 0.5)
		chunk_based_sort(lst_a, lst_b);
	else
		radix_sort(lst_a, lst_b, bench);
}
