/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:03:36 by palucena          #+#    #+#             */
/*   Updated: 2023/05/13 19:58:59 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Asigna memoria y comprueba que esté bien
void	*ft_calloc(size_t nb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size * nb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

//Comprueba la longitud de strings
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//Une dos strings y devuelve el combo
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s_total;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s_total = malloc((i + j + 1) * sizeof(char));
	if (!s_total)
		return (NULL);
	i = -1;
	while (s1[++i])
		s_total[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		s_total[i] = s2[j];
		i++;
	}
	s_total[i] = 0;
	return (s_total);
}

//Busca un carácter dentro de una string
int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//Cuenta los carácteres de una línea
int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
