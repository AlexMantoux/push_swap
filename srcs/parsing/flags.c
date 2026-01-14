/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:08:19 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/14 12:08:24 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_flags(char	*ret, t_flags	*flags)
{
	if (parse_flags(ret, flags))
		return (1);
	return (0);
}

int	parse_flags(char	*ret, t_flags	*flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
	if (ft_strcmp(ret, "--adaptive") == 0)
		flags->adaptive = 1;
	else if (ft_strcmp(ret, "--simple") == 0)
		flags->simple = 1;
	else if (ft_strcmp(ret, "--medium") == 0)
		flags->medium = 1;
	else if (ft_strcmp(ret, "--complex") == 0)
		flags->complex = 1;
	else if (ft_strcmp(ret, "--bench") == 0)
		flags->bench = 1;
	if (flags->simple == 0 || flags->medium == 0 || flags->complex == 0
		|| flags->bench == 0 || flags->adaptive == 0)
		return (0);
	return (1);
}
