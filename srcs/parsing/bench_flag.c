/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:40:37 by rtrutall          #+#    #+#             */
/*   Updated: 2026/08/22 23:44:53 by amantoux         ###   ########.fr       */
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
	bench->adaptive = 0;
	bench->complexity = '0';
	bench->silent = 0;
}

static int	compute_total_op(t_bench *bench)
{
	int	total;

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

static void	get_algo_name(t_bench *bench)
{
	if (bench->adaptive == 1)
	{
		ft_printf(2, "Adaptive / ");
		if (bench->complexity == 's')
			ft_printf(2, "O(n²)");
		else if (bench->complexity == 'm')
			ft_printf(2, "O(n√(n))");
		else if (bench->complexity == 'c')
			ft_printf(2, "O(nlog(n))");
	}
	else
	{
		if (bench->complexity == 's')
			ft_printf(2, "Simple / O(n²)");
		else if (bench->complexity == 'm')
			ft_printf(2, "Medium / O(n√(n))");
		else if (bench->complexity == 'c')
			ft_printf(2, "Complex / O(nlog(n))");
	}
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
	ft_printf(2, "rrr = %d\n", bench->rrr);
}

int	ft_count_strings(char **ret)
{
	int	i;

	i = 0;
	if (!ret)
		return (0);
	while (ret[i] != NULL)
		i++;
	return (i);
}
