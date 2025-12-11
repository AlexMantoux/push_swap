/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:14:18 by amantoux          #+#    #+#             */
/*   Updated: 2025/12/11 09:12:38 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_format(const char *c, int i, va_list args)
{
	int	count;

	count = 0;
	if (c[i] == '%')
		count += format_c('%');
	if (c[i] == 'c')
		count += format_c(va_arg(args, int));
	if (c[i] == 's')
		count += format_s(va_arg(args, char *));
	if (c[i] == 'd' || c[i] == 'i')
		count += format_d(va_arg(args, int));
	if (c[i] == 'u')
		count += format_u(va_arg(args, unsigned int));
	if (c[i] == 'x')
		count += format_x(va_arg(args, unsigned int));
	if (c[i] == 'X')
		count += format_x_upper(va_arg(args, unsigned int));
	if (c[i] == 'p')
		count += format_p(va_arg(args, void *));
	return (count);
}
