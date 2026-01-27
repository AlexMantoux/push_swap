/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:14:55 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/27 10:43:29 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(int fd, const char *c, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!c)
		return (-1);
	va_start(args, c);
	i = 0;
	count = 0;
	while (c[i])
	{
		if (c[i] == '%' && c[i + 1])
		{
			i++;
			count += handle_format(c, i, args, fd);
		}
		else
		{
			count++;
			format_c(fd, c[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
