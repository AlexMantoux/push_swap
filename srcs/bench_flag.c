/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:40:37 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/22 13:22:07 by amantoux         ###   ########.fr       */
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

void	display_bench(t_bench *bench, double disorder)
{
	ft_printf("[bench] disorder:    %f%%\n", disorder * 100);
	ft_printf("[bench] strategy:    %d\n", 1);
	ft_printf("[bench] total_ops:    %d\n", compute_total_op(bench));

	ft_printf("[bench] sa = %d    ", bench->sa);
	ft_printf("sb = %d    ", bench->sb);
	ft_printf("ss = %d    ", bench->ss);
	ft_printf("pa = %d    ", bench->pa);
	ft_printf("pb = %d\n", bench->pb);
	ft_printf("[bench] ra = %d    ", bench->ra);
	ft_printf("rb = %d    ", bench->rb);
	ft_printf("rr = %d    ", bench->rr);
	ft_printf("rra = %d    ", bench->rra);
	ft_printf("rrb = %d    ", bench->rrb);
	ft_printf("rrr = %d\n\n", bench->rrr);
}
