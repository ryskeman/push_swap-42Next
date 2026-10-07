/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:14:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/07 12:41:04 by jcortes          ###   ########.fr       */
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

void	print_num(void *n)
{
	char	*str;

	str = ft_itoa(*((int *) n));
	ft_putstr_fd(", ", 1);
	ft_putstr_fd(str, 1);
}

void	stack_print(t_list *stack)
{
	ft_lstiter(stack, &print_num);
	ft_putchar_fd('\n', 1);
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
	i = 1;
	stack = ft_lstnew(nums);
	while (i < len)
		push(&stack, &nums[i++]);
	return (stack);
}

int	main(void)
{
	t_list	*stack;
	int		nums[6] = {0, 1, 2, 3, 4, 5};

	stack = stack_create(nums, 6);
	stack_print(stack);
	swap(&stack);
	stack_print(stack);
	rotate(&stack);
	stack_print(stack);
	swap(&stack);
	stack_print(stack);
}
