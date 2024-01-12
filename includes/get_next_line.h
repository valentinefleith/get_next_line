/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/12 23:21:57 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

ssize_t				ft_read_and_stock(t_list **stock, int fd);
char				*ft_extract_line(t_list **stock);
size_t				ft_line_length(const t_list *stock);

t_list				*ft_lstnew(char content);
t_list				*ft_lstlast(const t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
int					ft_lst_contains(const t_list *lst, char c);
void				ft_lstfree(t_list **lst);

#endif
