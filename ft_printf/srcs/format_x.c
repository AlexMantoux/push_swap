/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:01:48 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/21 08:11:42 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_x(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	count++;
	if (n >= 16)
		count += format_x(n / 16);
	format_c(base[n % 16]);
	return (count);
}
