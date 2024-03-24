/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:49:28 by doji              #+#    #+#             */
/*   Updated: 2024/03/24 20:13:01 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*
int     main(void)
{
        char    *s;

        // STDIN_FILENO를 사용하여 표준 입력으로부터 읽기
        while ((s = get_next_line(STDIN_FILENO)))
        {
                printf("%s", s);
                free(s); // get_next_line에서 할당된 메모리 해제
        }

        return 0;
}
*/

int main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;
	int	fd;
	char	*s;

	fd1 = open("./test1.txt", O_RDONLY);
	fd2 = open("./test2.txt", O_RDONLY);
	fd3 = open("./test3.txt", O_RDONLY);
	fd4 = open("./test4.txt", O_RDONLY);
	fd5 = open("./test5.txt", O_RDONLY);
	fd = 0;
	while (fd < 10)
	{
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd3));
		printf("%s", get_next_line(fd4));
		printf("%s", get_next_line(fd5));
		printf("\n");
		fd++;
	}
	return (0);
}

