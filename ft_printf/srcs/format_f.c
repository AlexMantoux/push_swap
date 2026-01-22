/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:24:53 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 11:58:57 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_fraction(double frac_part, int precision)
{
	int	count;
	int	digit;

	count = 0;
	while (precision--)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		count += write(1, &"0123456789"[digit], 1);
		frac_part -= digit;
	}
	return (count);
}

int	format_f(double n)
{
	long long	int_part;
	double		frac_part;
	double		rounding;
	int			count;
	int			i;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	rounding = 0.5;
	i = 0;
	while (i++ < 2)
		rounding /= 10;
	n += rounding;
	int_part = (long long)n;
	frac_part = n - int_part;
	count += format_d(int_part);
	count += write(1, ".", 1);
	count += print_fraction(frac_part, 2);
	return (count);
}
