/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:00:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/09 17:23:24 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <sys/types.h>

char *get_next_line(int fd)
{
	static t_list *stash = NULL;
	char *line;
	int byte_count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byte_count = ft_read_and_stash(&stash, fd);
	if (byte_count == -1 || stash == NULL)
		return (NULL);

	
	return line;
}

ssize_t ft_read_and_stash(t_list **stash, int fd)
{
	char *buffer;
	ssize_t byte_count;

	buffer = malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (-1);
	byte_count = read(fd, buffer, buffer_size);
	buffer[byte_count] = '\0';
	ft_store_in_stash(stash, buffer, byte_count);
	free(buffer);
}

int ft_found_newline(t_list *stash)
{
	int i;

	if (stash == NULL)
		return (0);
	current = ft_lstlast(stash);
	i = 0;
	while(current->content[i])
	{
		if (current ->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
