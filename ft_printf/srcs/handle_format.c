/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:14:18 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 13:47:42 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_format(const char *c, int i, va_list args, int fd)
{
	int	count;

	count = 0;
	if (c[i] == '%')
		count += format_c('%', fd);
	if (c[i] == 'c')
		count += format_c(va_arg(args, int), fd);
	if (c[i] == 's')
		count += format_s(va_arg(args, char *), fd);
	if (c[i] == 'd' || c[i] == 'i')
		count += format_d(va_arg(args, int), fd);
	if (c[i] == 'f')
		count += format_f(va_arg(args, double), fd);
	if (c[i] == 'u')
		count += format_u(va_arg(args, unsigned int), fd);
	if (c[i] == 'x')
		count += format_x(va_arg(args, unsigned int), fd);
	if (c[i] == 'X')
		count += format_x_upper(va_arg(args, unsigned int), fd);
	if (c[i] == 'p')
		count += format_p(va_arg(args, void *), fd);
	return (count);
}
