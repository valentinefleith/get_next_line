/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:00:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/11 16:48:26 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{
	static t_list *stock = NULL;
	char *line;
	ssize_t byte_count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byte_count = BUFFER_SIZE;
	while (!ft_lst_contains(stock, '\n') && byte_count == BUFFER_SIZE)
	{
		byte_count = ft_read_and_stock(&stock, fd);
		if (byte_count == -1 || stock == NULL)
			return (NULL);
	}
	line = ft_get_line(stock);
	stock = ft_remove_line_from_stock(stock);
	if (!line || !*line)
	{
		ft_lstfree(&stock);
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

	buffer = malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (-1);
	byte_count = read(fd, buffer, BUFFER_SIZE);
	buffer[byte_count] = '\0';
	printf("%s\n", buffer);
	printf("%i\n", ft_lst_contains(*stock, '\n'));
	ft_lstadd_back_cpy(stock, buffer, byte_count);
	free(buffer);
	return byte_count;
}

t_list *ft_remove_line_from_stock(t_list *stock)
{
	t_list *last;
	t_list *new_stock;
	int i;
	int j;

	new_stock = malloc(sizeof(t_list));
	if (!stock || !new_stock)
		return NULL;
	new_stock->next = NULL;
	last = ft_lstlast(stock);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	new_stock->content = malloc(1 + sizeof(char) * (ft_strlen(last->content) - i));
	if (new_stock == NULL)
		return NULL;
	j = 0;
	while (last->content[i])
		new_stock->content[j++] = last->content[i++];
	new_stock->content[j] = '\0';
	ft_lstfree(&stock);
	return new_stock;
}

char *ft_get_line(t_list *stock)
{
	char *line;
	int content_index;
	int line_index;

	if (stock == NULL)
		return NULL;
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
	return line;
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