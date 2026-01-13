/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:09:14 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/12 10:09:44 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../../includes/push_swap.h"

char *big_str(char **argv)
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

char	**big_split(char const *str)
{
	char	**ret;

	ret = ft_split(str, ' ');
	return (ret);
}

void	error_check(char **argv)
{
	char	**ret;
	int i;

	i = 0;
	ret = big_split(big_str(argv));
	while (ret[i])
	{
		if (!ft_isdigit(ret[i]))
		{
			printf("Error\n");
			return ;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	char	**ret;
	int i;

	i = 0;
	ret = big_split(big_str(argv));
	while (ret[i])
	{
		if (!ft_isdigit(ret[i]))
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (ret[i])
	{
		printf("%ld\n", ft_atoi(ret[i]));
		i++;
	}
}