/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:40:37 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 14:49:10 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	init_bench(t_bench *bench)
{
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->algo = '0';
}

int compute_total_op(t_bench *bench)
{
	int total;

	total = 0;
	total += bench->pa;
	total += bench->pb;
	total += bench->sa;
	total += bench->sb;
	total += bench->ss;
	total += bench->ra;
	total += bench->rb;
	total += bench->rr;
	total += bench->rra;
	total += bench->rrb;
	total += bench->rrr;
	return (total);
}

void	get_algo_name(t_bench *bench)
{
	if (bench->algo == 's')
		ft_printf(1, "Simple / ");
	else if (bench->algo == 'm')
		ft_printf(1, "Medium / ");
	else if (bench->algo == 'c')
		ft_printf(1, "Complex / ");
	else if (bench->algo == 'a')
		ft_printf(1, "Adaptive / ");
}

void	display_bench(t_bench *bench, double disorder)
{
	ft_printf(2, "[bench] disorder:    %f%%\n", disorder * 100);
	ft_printf(2, "[bench] strategy:    ");
	get_algo_name(bench);
	ft_printf(2, "\n[bench] total_ops:    %d\n", compute_total_op(bench));
	ft_printf(2, "[bench] sa = %d    ", bench->sa);
	ft_printf(2, "sb = %d    ", bench->sb);
	ft_printf(2, "ss = %d    ", bench->ss);
	ft_printf(2, "pa = %d    ", bench->pa);
	ft_printf(2, "pb = %d\n", bench->pb);
	ft_printf(2, "[bench] ra = %d    ", bench->ra);
	ft_printf(2, "rb = %d    ", bench->rb);
	ft_printf(2, "rr = %d    ", bench->rr);
	ft_printf(2, "rra = %d    ", bench->rra);
	ft_printf(2, "rrb = %d    ", bench->rrb);
	ft_printf(2, "rrr = %d\n\n", bench->rrr);
}
