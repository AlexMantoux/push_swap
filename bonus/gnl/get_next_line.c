/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:42:38 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/30 10:45:38 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_buffer(char *tmp, char *buf, ssize_t readed)
{
	char	*joined;

	buf[readed] = '\0';
	joined = ft_strjoin_gnl(tmp, buf);
	free(tmp);
	return (joined);
}

static char	*read_and_join(int fd, char *rest)
{
	char		*buf;
	char		*tmp;
	ssize_t		readed;

	tmp = init_read(rest, &buf, &readed);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			free(tmp);
			return (NULL);
		}
		tmp = join_buffer(tmp, buf, readed);
		if (!tmp)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (tmp);
}

char	*ft_get_line(char *buf)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!buf || !*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

void	ft_get_rest(char *rest, char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		rest[0] = '\0';
		return ;
	}
	i++;
	while (buf[i])
		rest[j++] = buf[i++];
	rest[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1] = {0};
	char		*bigbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bigbuf = read_and_join(fd, rest);
	if (!bigbuf)
	{
		rest[0] = '\0';
		return (NULL);
	}
	line = ft_get_line(bigbuf);
	if (!line)
	{
		free(bigbuf);
		rest[0] = '\0';
		return (NULL);
	}
	ft_get_rest(rest, bigbuf);
	free(bigbuf);
	return (line);
}
