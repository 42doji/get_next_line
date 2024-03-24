/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:49:28 by doji              #+#    #+#             */
/*   Updated: 2024/03/24 16:07:49 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(void)
{
	int	fd;
	char	*s;

	fd = open("./test3.txt", O_RDONLY);
	while (s = get_next_line(fd))
	{
		printf("%s", s);
		printf("dd\n");
		free(s);
	}
	return (0);
}
