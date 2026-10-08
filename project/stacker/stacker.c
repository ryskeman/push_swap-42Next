/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:14:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/08 09:07:43 by jcortes          ###   ########.fr       */
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

void	swap(t_list **lst)
{
	t_list	*n1;
	t_list	*n2;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	n1 = stack_pop(lst);
	n2 = stack_pop(lst);
	stack_push(lst, n1);
	stack_push(lst, n2);
}

void	push(t_list **lst, int *n)
{
	t_list	*new;

	new = ft_lstnew(n);
	if (new == NULL)
		return ;
	stack_push(lst, new);
}

void	rotate(t_list **lst)
{
	t_list	*head;

	if (lst == NULL || *lst == NULL)
		return ;
	head = stack_pop(lst);
	head->next = NULL;
	ft_lstadd_back(lst, head);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tail;

	if (lst == NULL || *lst == NULL)
		return ;
	tail = stack_shift(lst);
	stack_push(lst, tail);
}

t_list	*stack_create(int *nums, int len)
{
	int		i;
	t_list	*stack;

	if (len == 0)
		return (NULL);
	i = 0;
	stack = NULL;
	while (i < len)
		push(&stack, &nums[i++]);
	return (stack);
}
