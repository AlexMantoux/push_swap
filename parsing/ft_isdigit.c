/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:49:42 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/12 15:49:46 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(char *str)
{
	int i;
	i = 0;

	while (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}