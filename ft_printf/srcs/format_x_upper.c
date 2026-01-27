/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:35:40 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/27 10:57:33 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_x_upper(unsigned long n, int fd)
{
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	count++;
	if (n >= 16)
		count += format_x_upper(n / 16, fd);
	format_c(fd, base[n % 16]);
	return (count);
}
