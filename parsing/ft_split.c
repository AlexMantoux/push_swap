/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrutall <rtrutall@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:46:27 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/12 10:46:44 by rtrutall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	count_words(char const *s, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && is_charset(s[i], charset))
			i++;
		if (s[i] && !is_charset(s[i], charset))
			count++;
		while (s[i] && !is_charset(s[i], charset))
			i++;
	}
	return (count);
}

static char	*ft_words(char const *s, char charset)
{
	char	*ret;
	int		i;

	i = 0;
	while (s[i] && !is_charset(s[i], charset))
		i++;
	ret = malloc (sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && !is_charset(s[i], charset))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		j;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !is_charset(*s, c))
		{
			ret[j] = ft_words(s, c);
			if (!ret[j++])
				return (free_tab(ret), NULL);
			while (*s && !is_charset(*s, c))
				s++;
		}
	}
	ret[j] = NULL;
	return (ret);
}