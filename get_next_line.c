/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:25:20 by doji              #+#    #+#             */
/*   Updated: 2024/03/24 16:23:15 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	_lcat(char *dst, char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + j);
}

void	_mmove(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (dst < src)
	{
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = size - 1;
		while (i >= 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
}

char	*_rem_check(char **rem, char *line)
{
	int	n_idx;

	n_idx = _chr(*rem, '\n');
	if ((n_idx) >= 0)
	{
		line = _dup(*rem);
		line[n_idx + 1] = '\0';
		_mmove(*rem, *rem + n_idx + 1, _len(*rem + n_idx + 1) + 1);
		return (line);
	}
	if (*rem && **rem)
	{
		free(*rem);
		*rem = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rem[1024];
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			idx;

	line = NULL;
	ret = read(fd, buf, BUFFER_SIZE);
	while ((ret > 0))
	{	
		buf[ret] = '\0';
		rem[fd] = _join_free(&rem[fd], buf);
		idx = _chr(rem[fd], '\n');
		if ((idx) >= 0)
		{
			line = _dup(rem[fd]);
			line[idx + 1] = '\0';
			_mmove(rem[fd], rem[fd] + idx + 1, _len(rem[fd] + idx + 1) + 1);
			return (line);
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	line = _rem_check(&rem[fd], line);
	return (line);
}
