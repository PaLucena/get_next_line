/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:41 by palucena          #+#    #+#             */
/*   Updated: 2024/02/28 20:23:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief locates the an occurrence of c (converted to a char) in
 * 			the string pointed to by s.
 * 
 * @param str -> String to search in.
 * @param c -> Character to find (as int).
 * @return bool -> Return true 
 */
bool	ft_strchr(const char *str, int c)
{
	if (!*str && (char)c == '\0')
		return (true);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
		if (*str == (char)c)
			return (true);
	}
	return (false);
}

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * 		  result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param s1 -> The prefix string
 * @param s2 -> The suffix string
 * @return char* -> The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s_total;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s_total = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s_total)
		return (0);
	i = -1;
	while (s1[++i])
		s_total[i] = s1[i];
	j = -1;
	while (s2[++j])
		s_total[i++] = s2[j];
	s_total[i] = 0;
	return (s_total);
}

/**
 * @brief Allocates sufficient memory for a copy of the string s1,
 * 		  does the copy, and returns a pointer to it.
 * 
 * @param s -> string to copy
 * @return char* -> pointer to the copy of s
 */
char	*ft_strdup(const char *s)
{
	char		*s2;
	size_t		i;

	i = -1;
	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (++i <= (size_t)(ft_strlen(s)))
		s2[i] = s[i];
	return (s2);
}

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * 		  The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s -> The string from which to create the substring.
 * @param start -> The start index of the substring in the string ’s’.
 * @param len -> The maximum length of the substring.
 * @return char* -> The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub || !s)
		return (0);
	i = 0;
	while (s[start])
	{
		if (i < len)
			sub[i++] = s[start];
		start++;
	}
	sub[i] = 0;
	return (sub);
}

/**
 * @brief Calculates the length of the string pointed to by str, excluding the
 * 		  terminating null byte ('\0').
 * 
 * @param str -> string to calculate the length of
 * @return int -> length of the string
 */
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
