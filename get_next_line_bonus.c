/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:30 by palucena          #+#    #+#             */
/*   Updated: 2024/02/28 20:35:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_stuff(char *total, char *buf, int fd)
{
	char	*tmp;
	int		nb_read;

	if (!total)
		total = ft_strdup("");
	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		buf[nb_read] = '\0';
		tmp = total;
		total = ft_strjoin(tmp, buf);
		free (tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (total);
}

static char	*ft_clean(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (rest[0] == '\0')
		return (free(rest), NULL);
	line[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
	{
		if (rest[fd])
			free(rest[fd]);
		return (NULL);
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(buf), NULL);
	line = read_stuff(rest[fd], buf, fd);
	free(buf);
	if (!line)
		return (NULL);
	rest[fd] = ft_clean(line);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
