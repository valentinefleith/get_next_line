/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:54:45 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/12 00:27:04 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
}

// void ft_lstadd_front(t_list **lst, t_list *new_node)
//{
//	new_node->next = *lst;
//	*lst = new_node;
//}

t_list	*ft_lstnew(char content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (node);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lst_contains(t_list *lst, char c)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		if (lst->content == c)
			return (1);
		i++;
		lst = lst->next;
	}
	return (0);
}

void	ft_lstfree(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
