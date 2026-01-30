/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:32:58 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/30 07:58:51 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen_gnl(s1);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (NULL);
	ret = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
