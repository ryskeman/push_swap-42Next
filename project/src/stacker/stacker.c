/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:56:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 13:13:54 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

t_list	**create_stacks(int *nums, int len)
{
	t_list	**stacks;

	stacks = ft_calloc(2, sizeof(t_list));
	stacks[0] = stack_create(nums, len);
	stacks[1] = stack_create(NULL, 0);
	return (stacks);
}

void	stack_operate(t_operation op, t_list **stacks)
{
	if (op == sa)
		return (swap(&stacks[0]));
	if (op == sb)
		return (swap(&stacks[1]));
	if (op == ss)
		return (swap(&stacks[0]), swap(&stacks[1]));
	if (op == pa)
		return (stack_push(&stacks[0], stack_pop(&stacks[1])));
	if (op == pb)
		return (stack_push(&stacks[1], stack_pop(&stacks[0])));
	if (op == ra)
		return (rotate(&stacks[0]));
	if (op == rb)
		return (rotate(&stacks[1]));
	if (op == rr)
		return (rotate(&stacks[0]), rotate(&stacks[1]));
	if (op == rra)
		return (reverse_rotate(&stacks[0]));
	if (op == rrb)
		return (reverse_rotate(&stacks[1]));
	if (op == rrr)
		return (reverse_rotate(&stacks[0]), reverse_rotate(&stacks[1]));
}
