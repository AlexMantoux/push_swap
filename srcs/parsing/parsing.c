/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:09:14 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/13 13:13:24 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

static char	*big_str(char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = argv[i];
	i++;
	while (argv[i])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	return (str);
}

static char	**big_split(char const *str)
{
	char	**ret;

	ret = ft_split(str, ' ');
	return (ret);
}

static int	error_check_digits(char **ret)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (ret[i])
	{
		if (!ft_isdigit(ret[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		n = ft_atoi(ret[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	find_in_lst(t_list *lst_a, int value)
{
	while (lst_a != NULL)
	{
		if (lst_a->content == value)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

int	complete_lst(char **argv, t_list	**lst_a, t_flags	*flags)
{
	char	**ret;
	int		i;
	int		f;

	i = 0;
	ret = big_split(big_str(argv));
	f = parse_flags(ret[0], flags);
	if (!error_check_digits(ret + f))
		return (0);
	*lst_a = ft_lstnew((int)ft_atoi(ret[i + f]));
	i++;
	while (ret[i + f])
	{
		if (!find_in_lst(*lst_a, (int)ft_atoi(ret[i + f])))
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_lstadd_back(lst_a, ft_lstnew((int)ft_atoi(ret[i + f])));
		i++;
	}
	return (1);
}
