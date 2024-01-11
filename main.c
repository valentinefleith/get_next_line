/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:55:27 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/11 20:53:18 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int i = 1;

	fd = open("texts/text1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Line %i : %s\n", i, line);
	//while(1)
	//{
	//	line = get_next_line(fd);
	//	if (!line)
	//	{
	//		free(line);
	//		break;
	//	}
	//	printf("Line %i : %s\n", i, line);
	//	i++;
	//	free(line);
	//}
	return 0;
}
