/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:00:55 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/27 10:57:02 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_u(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count += format_c(fd, n + '0');
		return (count);
	}
	count += format_d(n / 10, fd);
	count += format_c(fd, (n % 10) + '0');
	return (count);
}
