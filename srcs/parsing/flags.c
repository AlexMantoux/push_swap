/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:08:19 by rtrutall          #+#    #+#             */
/*   Updated: 2026/08/22 23:44:54 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	flags_init(t_flags	*flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
}

int	check_dooble_flags(char	*ret, t_flags	*flags)
{
	parse_flags(ret, flags);
	if (flags->bench && (flags->simple || flags->medium || flags->complex
			|| flags->adaptive))
		return (1);
	return (0);
}

int	parse_flags(char	*ret, t_flags	*flags)
{
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
	if (flags->simple || flags->medium || flags->complex
		|| flags->bench || flags->adaptive)
		return (1);
	return (0);
}

void	flag_execution(t_flags	flags, t_list	**lst_a, t_list	**lst_b,
			t_bench	*bench)
{
	float	disorder;

	disorder = compute_disorder(*lst_a);
	if (flags.simple)
		selection_sort(lst_a, lst_b, bench);
	if (flags.medium)
		chunk_based_sort(lst_a, lst_b, bench);
	if (flags.complex)
		radix_sort(lst_a, lst_b, bench);
	if (!(flags.simple || flags.medium || flags.complex))
		adaptive_sort(disorder, lst_a, lst_b, bench);
}
