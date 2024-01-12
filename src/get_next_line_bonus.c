/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:15:48 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/12 13:59:29 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stdio.h>

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("%c", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

char	*get_next_line(int fd)
{
	static t_list	*stock[1024];
	char			*line;
	ssize_t			byte_count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byte_count = BUFFER_SIZE;
	while (!ft_lst_contains(stock[fd], '\n') && byte_count == BUFFER_SIZE)
	{
		byte_count = ft_read_and_stock(&stock[fd], fd);
		if (byte_count == -1 || stock[fd] == NULL)
			return (NULL);
	}
	line = ft_extract_line(&stock[fd]);
	if (!line || !*line)
	{
		ft_lstfree(&stock[fd]);
		stock[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

ssize_t	ft_read_and_stock(t_list **stock, int fd)
{
	char	*buffer;
	ssize_t	byte_count;
	ssize_t	i;

	buffer = malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (-1);
	byte_count = read(fd, buffer, BUFFER_SIZE);
	buffer[byte_count] = '\0';
	i = 0;
	while (i < byte_count)
	{
		ft_lstadd_back(stock, ft_lstnew(buffer[i]));
		i++;
	}
	free(buffer);
	return (byte_count);
}

char	*ft_extract_line(t_list **stock)
{
	char	*line;
	ssize_t	i;
	t_list	*next;

	if (stock == NULL)
		return (NULL);
	line = malloc((1 + ft_line_length(*stock)) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (*stock)
	{
		line[i] = (*stock)->content;
		i++;
		next = (*stock)->next;
		free(*stock);
		*stock = next;
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

size_t	ft_line_length(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		if (lst->content == '\n')
			break ;
		lst = lst->next;
	}
	return (len);
}
