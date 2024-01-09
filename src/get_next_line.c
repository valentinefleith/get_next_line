/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:00:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/09 14:08:53 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <sys/types.h>

char *get_next_line(int fd)
{
	static t_list *stash;
	char *line;
	int status;

	status = ft_read_file(&stash, fd, BUFFER_SIZE);

	
	return line;
}

ssize_t ft_read_file(t_list **stash, int fd, buffer_size)
{
	char *buffer;
	ssize_t byte_count;

	buffer = malloc(buffer_size * sizeof(char));
	if (!buffer)
		return (-1);
	byte_count = read(fd, buffer, buffer_size);
	ft_store_in_stash(stash, buffer, byte_count);
	free(buffer);
}

void ft_store_in_stash(t_list **stash, char *buffer, ssize_t byte_count)
{

}
