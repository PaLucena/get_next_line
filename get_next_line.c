/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:41:17 by palucena          #+#    #+#             */
/*   Updated: 2023/05/13 20:15:34 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_char(int fd, char *str_ac)
{
	char	*tmp;
	int		nb;

	if (!str_ac)
		str_ac = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, tmp, BUFFER_SIZE);
		if (nb < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[nb] = '\0';
		str_ac = ft_concat_str(str_ac, tmp);
		if (ft_strchr(str_ac, '\n') == 1)
			break ;
	}
	free (tmp);
	return (str_ac);
}

char	*ft_concat_str(char *str_ac, char *tmp)
{
	char	*combo;

	combo = ft_strjoin(str_ac, tmp);
	free(str_ac);
	return (combo);
}

char	*ft_get_line(char *str_ac)
{
	char	*line;
	int		i;

	i = 0;
	if (str_ac[i] == '\0')
		return (NULL);
	while (str_ac[i] != '\0' && str_ac[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str_ac[i] != '\0' && str_ac[i] != '\n')
	{
		line[i] = str_ac[i];
		i++;
	}
	if (str_ac[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_memclear(char *str_ac)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	while (str_ac[i] && str_ac[i] != '\n')
		i++;
	if (str_ac[i] == '\0')
	{
		free(str_ac);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(str_ac) - i + 1, sizeof(char));
	i++;
	while (str_ac[i] != '\0')
		new_line[j++] = str_ac[i++];
	free(str_ac);
	if (new_line[0] == '\0')
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*str_ac;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (str_ac != NULL)
		{
			free(str_ac);
			str_ac = NULL;
		}
		return (NULL);
	}
	str_ac = ft_find_char(fd, str_ac);
	line = ft_get_line(str_ac);
	str_ac = ft_memclear(str_ac);
	return (line);
}
