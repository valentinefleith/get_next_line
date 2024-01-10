/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/10 21:15:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

typedef struct s_list
{
	char *content;
	struct s_list *next;
}
	t_list;

ssize_t ft_read_and_stock(t_list **stash, int fd);
int ft_stock_contains(t_list *stash, char c);
void ft_stock_addback(t_list *stash, char *buffer, ssize_t byte_count);


#endif