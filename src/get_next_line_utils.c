/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:08 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/10 21:28:52 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (node);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list *ft_lstlast(t_list *lst)
{
	while(lst && lst->next)
		lst = lst->next;
	return (lst);
}


int ft_lst_contains(t_list *lst, char c)
{
	int i;
	t_list *current;

	if (lst == NULL)
		return (0);
	current = ft_lstlast(lst);
	i = 0;
	while(current->content[i])
	{
		if (current ->content[i] == c)
			return (1);
		i++;
	}
	return (0);
}
