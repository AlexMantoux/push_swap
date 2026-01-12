/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:00:04 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/21 08:11:28 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_d(int n)
{
	int	count;

	count = 0;
	count++;
	if (n == -2147483648)
	{
		format_s("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		format_c('-');
		n *= -1;
		count++;
	}
	if (n < 10)
	{
		format_c(n + '0');
		return (count);
	}
	count += format_d(n / 10);
	format_c((n % 10) + '0');
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	format_d(465);
// 	printf("\n%d", format_d(-44654564));
// 	return (0);
// }