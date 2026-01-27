/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:01:48 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/27 10:57:43 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_x(unsigned long n, int fd)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	count++;
	if (n >= 16)
		count += format_x(n / 16, fd);
	format_c(fd, base[n % 16]);
	return (count);
}
