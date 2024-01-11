/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/11 20:27:53 by vafleith         ###   ########.fr       */
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
	char content;
	struct s_list *next;
}
	t_list;

ssize_t ft_read_and_stock(t_list **stock, int fd);
char *ft_get_line_and_remove_from_stock(t_list **stock);
t_list *ft_remove_line_from_stock(t_list *stock);

size_t ft_line_length(t_list *stock);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back_cpy(t_list **stock, char *buffer, ssize_t byte_count);
int ft_lst_contains(t_list *stash, char c);
void ft_lstfree(t_list **lst);
size_t ft_strlen(char *str);

void ft_lstadd_back(t_list **lst, t_list *new_node);
void ft_lstadd_front(t_list **lst, t_list *new_node);
t_list *ft_lstnew(char content);

#endif
