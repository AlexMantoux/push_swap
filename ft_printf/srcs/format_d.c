/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:00:04 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 13:43:50 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_d(int n, int fd)
{
	int	count;

	count = 0;
	count++;
	if (n == -2147483648)
	{
		format_s("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		format_c('-', fd);
		n *= -1;
		count++;
	}
	if (n < 10)
	{
		format_c(n + '0', fd);
		return (count);
	}
	count += format_d(n / 10, fd);
	format_c((n % 10) + '0', fd);
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	format_d(465);
// 	printf("\n%d", format_d(-44654564));
// 	return (0);
// }