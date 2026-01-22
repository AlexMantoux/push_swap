/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:36:22 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 13:45:03 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_p(void *p, int fd)
{
	unsigned long	ad;
	int				count;

	count = 0;
	ad = (unsigned long)p;
	if (ad == 0)
		return (format_s("(nil)", fd), 5);
	else
	{
		count += format_s("0x", fd);
		count += format_x(ad, fd);
	}
	return (count);
}
