/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:36:22 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/21 10:52:24 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_p(void *p)
{
	unsigned long	ad;
	int				count;

	count = 0;
	ad = (unsigned long)p;
	if (ad == 0)
		return (format_s("(nil)"), 5);
	else
	{
		count += format_s("0x");
		count += format_x(ad);
	}
	return (count);
}
