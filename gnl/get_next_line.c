/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:32:54 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/30 07:58:02 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_and_join(int fd, char *rest)
{
	char		*buf;
	char		*tmp;
	char		*joined;
	ssize_t		readed;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	readed = 1;
	tmp = rest;
	while (!ft_strchr_gnl(tmp, '\n') && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		joined = ft_strjoin_gnl(tmp, buf);
		if (!joined)
		{
			free(buf);
			return (NULL);
		}
		if (tmp != rest)
			free(tmp);
		tmp = joined;
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

char    *get_next_line(int fd)
{
    static char rest[BUFFER_SIZE + 1] = {0};
    char        *bigbuf;
    char        *line;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);

    bigbuf = read_and_join(fd, rest);
    if (!bigbuf)
        return (NULL);

    line = ft_get_line(bigbuf);
    ft_get_rest(rest, bigbuf);

	if (bigbuf != rest)
        free(bigbuf);

    return (line);
}


// int main(void)
// {
// 	int     fd;
// 	char    *line;
// 	int     i = 1;

// 	fd = open("test", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	i++;

// 	close(fd);
// 	return (0);

// 	// char rest[42];
// 	// char *line;
// 	// char str[42] = "abcdefgh\nijkl";

// 	// line = get_line(str);
// 	// printf("%s\n", line);
// 	// get_rest(rest, str);
// 	// printf("%s\n", rest);
// }