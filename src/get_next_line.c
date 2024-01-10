/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:00:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/10 22:13:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *stock = NULL;
	char *line;
	int byte_count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byte_count = ft_read_and_stock(&stock, fd);
	if (byte_count == -1 || stock == NULL)
		return (NULL);
	line = ft_get_line(stock);
	ft_lstclear(&stock);
	if (!line || !*line)
	{
		ft_lstfree(stock);
		stock = NULL;
		free(line);
		return (NULL);
	}
	return line;
}

ssize_t ft_read_and_stock(t_list **stock, int fd)
{
	char *buffer;
	ssize_t byte_count;

	byte_count = BUFFER_SIZE;
	while (!ft_stock_contains(*stock, '\n') && byte_count == BUFFER_SIZE)
	{
		buffer = malloc(1 + BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (-1);
		byte_count = 0;
		byte_count = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_count] = '\0';
		ft_lstadd_back_cpy(stock, buffer, byte_count);
	}
	free(buffer);
	return byte_count;
}

void ft_lstadd_back_cpy(t_list **stock, char *buffer, ssize_t byte_count)
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
	new->content[i] = '\0';
	if (!*stock)
	{
		*stock = last;
		return;
	}
	last = ft_lstlast(*stock);
	last->next = new;
}

char *ft_get_line(t_list *stock)
{
	char *line;
	int content_index;
	int line_index;

	if (stock == NULL)
		return;
	line = malloc(1 + sizeof(char) * ft_line_length(stock));
	if (!line)
		return NULL;
	line_index = 0;
	while(stock)
	{
		content_index = 0;
		while(stock->content[content_index])
		{
			if (stock->content[content_index] == '\n')
			{
				line[line_index++] = '\n';
			}
			line[line_index++] = stock->content[content_index++];
		}
		stock = stock->next;
	}
	line[line_index] = '\0';
}

size_t ft_line_length(t_list *stock)
{
	int i;
	size_t len;

	len = 0;
	while(stock != NULL)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stock = stock->next;
	}
	return len;
}

