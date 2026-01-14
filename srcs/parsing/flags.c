/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:38:05 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/14 08:50:53 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void parse_flags(int argc, char **argv, t_flags *flags)
{
    int i;

    flags->simple = 0;
    flags->medium = 0;
    flags->complex = 0;
    flags->bench = 0;
    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--simple") == 0)
            flags->simple = 1;
        else if (ft_strcmp(argv[i], "--medium") == 0)
            flags->medium = 1;
        else if (ft_strcmp(argv[i], "--complex") == 0)
            flags->complex = 1;
        else if (ft_strcmp(argv[i], "--bench") == 0)
            flags->bench = 1;
        i++;
    }
}
