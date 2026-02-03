/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:04:12 by amantoux          #+#    #+#             */
/*   Updated: 2026/02/03 10:31:33 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

static int	init_parsing(char **argv, char ***ret, char **big_string)
{
	*big_string = big_str(argv);
	if (!*big_string)
		return (0);
	*ret = big_split(*big_string);
	if (!*ret)
	{
		free(*big_string);
		return (0);
	}
	return (1);
}

static int	validate_input(char **ret, t_flags *flags, char *big_string)
{
	int	f;

	f = parse_flags(ret[0], flags);
	if (f && ret[1])
		f += check_dooble_flags(ret[1], flags);
	if (!ret[f])
	{
		free_tab(ret);
		free(big_string);
		return (-1);
	}
	if (!error_check_digits(ret + f))
	{
		free_tab(ret);
		free(big_string);
		return (-1);
	}
	return (f);
}

static void	cleanup_and_error(char **ret, char *big_string, t_list **lst_a)
{
	ft_printf(2, "Error\n");
	free_tab(ret);
	free(big_string);
	ft_lstclear(lst_a);
}

static int	populate_list(char **ret, int f, t_list **lst_a)
{
	int	i;

	i = 0;
	*lst_a = ft_lstnew((int)ft_atoi(ret[i + f]));
	i++;
	while (ret[i + f])
	{
		if (!find_in_lst(*lst_a, (int)ft_atoi(ret[i + f])))
			return (0);
		ft_lstadd_back(lst_a, ft_lstnew((int)ft_atoi(ret[i + f])));
		i++;
	}
	return (1);
}

int	complete_lst(char **argv, t_list **lst_a, t_flags *flags)
{
	char	**ret;
	char	*big_string;
	int		f;
	int		i;

	if (!init_parsing(argv, &ret, &big_string))
		return (0);
	f = validate_input(ret, flags, big_string);
	i = ft_count_strings(ret);
	if (f == -1 || f + 1 >= i)
	{
		free_tab(ret);
		free(big_string);
		return (0);
	}
	if (!populate_list(ret, f, lst_a))
	{
		cleanup_and_error(ret, big_string, lst_a);
		return (0);
	}
	free_tab(ret);
	free(big_string);
	return (1);
}
