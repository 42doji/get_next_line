/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:54:20 by doji              #+#    #+#             */
/*   Updated: 2024/04/12 18:18:02 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

char	*get_next_line(int fd);
int		_len(char *s);
int		_chr(char *s, char c);
char	*_dup(char *str);
int		_lcpy(char *dst, char *src, int size);
char	*_join_free(char **s1, char *s2);
void	_mmove(char *dst, char *src, int size);
char	*_rem_check(char **rem, char *line);
char	*get_next_line(int fd);
char	*_return_line(int idx, int fd, char **rem);

#endif
