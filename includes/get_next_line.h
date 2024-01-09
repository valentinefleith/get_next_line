/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/09 15:06:24 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

typedef struct s_list
{
	void *content;
	struct s_list *next;
}
	t_list;

ssize_t ft_read_file(t_list **stash, int fd, int buffer_size);
void ft_store_in_stash(t_list **stash, char *buffer, ssize_t byte_count);

#endif
