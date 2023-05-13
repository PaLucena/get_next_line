/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:42:01 by palucena          #+#    #+#             */
/*   Updated: 2023/05/13 20:00:42 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_find_char(int fd, char *str_ac);
char	*ft_concat_str(char *str_ac, char *tmp);
char	*ft_get_line(char *str_ac);
char	*ft_memclear(char *str_ac);
char	*get_next_line(int fd);

void	*ft_calloc(size_t nb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *str, int c);
int		ft_linelen(char *str);

#endif