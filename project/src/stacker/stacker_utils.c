/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:33:39 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 10:35:14 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

t_list	*stack_pop(t_list **lst)
{
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	node = *lst;
	*lst = node->next;
	return (node);
}

t_list	*stack_shift(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	node = *lst;
	while (node)
	{
		if (node->next != NULL && node->next->next == NULL)
		{
			tmp = node->next;
			node->next = NULL;
		}
		node = node->next;
	}
	return (tmp);
}

void	stack_push(t_list **lst, t_list *new)
{
	ft_lstadd_front(lst, new);
}
