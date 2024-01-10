/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:00:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/10 21:07:06 by vafleith         ###   ########.fr       */
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
	line = ft_extract_line(stash);
	ft_clean_stash(&stash);
	if (!line[0])
	{
		ft_free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return line;
}

ssize_t ft_read_and_stash(t_list **stash, int fd)
{
	char *buffer;
	ssize_t byte_count;

	while (!ft_stash_contains(*stash, '\n') && byte_count == BUFFER_SIZE)
	{
		buffer = malloc(1 + BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (-1);
		byte_count = 0;
		byte_count = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_count] = '\0';
		ft_stash_addback(stash, buffer, byte_count);
	}
	free(buffer);
	return byte_count;
}

void ft_stashadd_back(t_list **stash, char *buffer, ssize_t byte_count)
{
	t_list *last;
	t_list *new;
	int i;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(1 + sizeof(char) * byte_count);
	if (new->content == NULL)
		return ;
	i = 0;
	while (buffer[i])
	{
		new->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*stash)
	{
		*stash = last;
		return;
	}
	last = ft_lstlast(*stash);
	last->next = new;
}

int ft_stash_contains(t_list *stash, char c)
{
	int i;

	if (stash == NULL)
		return (0);
	current = ft_lstlast(stash);
	i = 0;
	while(current->content[i])
	{
		if (current ->content[i] == c)
			return (1);
		i++;
	}
	return (0);
}
