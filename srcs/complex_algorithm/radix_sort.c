/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:39:24 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 14:46:22 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
	int	i;
	int	j;
	int	max_index;
	int	max_bits;

	max_index = ft_lstsize(*lst_a);
	max_bits = get_max_bits(max_index - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < max_index)
		{
			if ((((*lst_a)->index >> i) & 1) == 1)
				rotate_a(lst_a, bench);
			else
				push_b(lst_a, lst_b, bench);
			j++;
		}
		while (*lst_b)
			push_a(lst_a, lst_b, bench);
		i++;
	}
	bench->algo = 'c';
}
