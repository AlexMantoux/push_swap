/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:09:14 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/29 14:07:11 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

static size_t	ft_strlen_dup(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ret;

	len = ft_strlen_dup(s1);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*big_str(char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		temp = ft_strjoin(result, " ");
		free(result);
		result = temp;
		temp = ft_strjoin(result, argv[i]);
		free(result);
		result = temp;
		i++;
	}
	return (result);
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
			ft_printf(2, "Error\n");
			return (0);
		}
		n = ft_atoi(ret[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			ft_printf(2, "Error\n");
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
	char	*big_string;
	int		i;
	int		f;

	i = 0;
	big_string = big_str(argv);
	if (!big_string)
		return (0);
	ret = big_split(big_string);
	if (!ret)
	{
		free(big_string);
		return (0);
	}
	f = parse_flags(ret[0], flags);
	if (f)
		f += check_dooble_flags(ret[1], flags);
	if (!error_check_digits(ret + f))
	{
		free_tab(ret);
		free(big_string);
		return (0);
	}
	*lst_a = ft_lstnew((int)ft_atoi(ret[i + f]));
	i++;
	while (ret[i + f])
	{
		if (!find_in_lst(*lst_a, (int)ft_atoi(ret[i + f])))
		{
			ft_printf(2, "Error\n");
			free_tab(ret);
			free(big_string);
			ft_lstclear(lst_a);
			return (0);
		}
		ft_lstadd_back(lst_a, ft_lstnew((int)ft_atoi(ret[i + f])));
		i++;
	}
	free_tab(ret);
	free(big_string);
	return (1);
}
