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

char *parsing_str(char *argv)
{
	int i;
	int n;
	i = 0;
	while (argv[i])
	{
		i++;
		if (argv[i] == ' ')
			//appeler une fonction qui split les espaces
	}
	n = ft_atoi(argv);
	return (n);
}
