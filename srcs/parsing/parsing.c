/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:09:14 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/13 11:59:01 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

static char *big_str(char **argv)
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

static int	error_check_digits(char **argv)
{
	char	**ret;
	int		i;
	long	n;

	i = 0;
	n = 0;
	ret = big_split(big_str(argv));
	while (ret[i])
	{
		if (!ft_isdigit(ret[i]))
		{
			printf("Error\n");
			return (0);
		}
		n = ft_atoi(ret[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	complete_lst(char **argv, t_list  *lst_a, t_list  *lst_b)
{
	char	**ret;
	int i;

	i = 0;
	ret = big_split(big_str(argv));
	if (!error_check_digits(argv))
		return (0);
	lst_a = ft_lstnew((int)ft_atoi(argv[i]));
	lst_b = NULL;
	while (ret[i])
	{
		ft_lstadd_back(&lst_a, ft_lstnew((int)ft_atoi(argv[i])));
		i++;
	}
	return (1);
}

// int main(int argc, char **argv)
// {
// 	t_list  *lst_a;
// 	t_list  *lst_b;
//
// 	lst_a = NULL;
// 	lst_b = NULL;
//
// 	complete_lst(argv, lst_a, lst_b);
// 	ft_lstdisplay(&lst_a, 'a');
// 	ft_lstdisplay(&lst_b, 'b');
// 	printf("______________________________\n");
// 	selection_sort(&lst_a, &lst_b);
// 	ft_lstdisplay(&lst_a, 'a');
// 	ft_lstdisplay(&lst_b, 'b');
// 	printf("______________________________\n");
// }