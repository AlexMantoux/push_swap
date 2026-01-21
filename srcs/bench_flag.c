/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:40:37 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/21 17:40:43 by rtrutall         ###   ########.fr       */
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
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	display_bench(t_bench *bench)
{
	ft_printf("pa = %d     ", bench->pa);
	ft_printf("pa = %d\n", bench->pb);
	ft_printf("sa = %d     ", bench->sa);
	ft_printf("sb = %d\n", bench->sb);
	ft_printf("ra = %d     ", bench->ra);
	ft_printf("rb = %d     ", bench->rb);
	ft_printf("rr = %d\n", bench->rr);
	ft_printf("ra = %d     ", bench->rra);
	ft_printf("rb = %d     ", bench->rrb);
	ft_printf("rrr = %d\n", bench->rrr);
}
