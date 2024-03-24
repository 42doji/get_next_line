/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:32:27 by doji              #+#    #+#             */
/*   Updated: 2024/03/23 23:25:28 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	_chr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*_dup(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	len = _len(str);
	i = 0;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	_lcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*_join_free(char **s1, char *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(_len(*s1) + _len(s2) + 1);
	if (!new_str)
		return (NULL);
	while (*s1 && (*s1)[i])
	{
		new_str[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		new_str[_len(*s1) + i] = s2[i];
		i++;
	}
	new_str[_len(*s1) + i] = '\0';
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (new_str);
}
