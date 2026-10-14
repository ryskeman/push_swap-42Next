/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:56:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 14:12:57 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

void	fill_state(int *nums, int len, t_state *state)
{
	state->a = stack_create(nums, len);
	state->b = stack_create(NULL, 0);
}

void	stack_operate(t_operation op, t_state *state)
{
	if (op == sa)
		return (swap(&state->a));
	if (op == sb)
		return (swap(&state->b));
	if (op == ss)
		return (swap(&state->a), swap(&state->b));
	if (op == pa)
		return (stack_push(&state->a, stack_pop(&state->b)));
	if (op == pb)
		return (stack_push(&state->b, stack_pop(&state->a)));
	if (op == ra)
		return (rotate(&state->a));
	if (op == rb)
		return (rotate(&state->b));
	if (op == rr)
		return (rotate(&state->a), rotate(&state->b));
	if (op == rra)
		return (reverse_rotate(&state->a));
	if (op == rrb)
		return (reverse_rotate(&state->b));
	if (op == rrr)
		return (reverse_rotate(&state->a), reverse_rotate(&state->b));
}

int	*export_state(t_state *state)
{
	int		*nums;
	size_t	i;
	size_t	len;
	t_list	*node;

	if (ft_lstsize(state->b) > 0)
		return (NULL);
	len = ft_lstsize(state->a);
	nums = ft_calloc(len + 1, sizeof(int));
	i = 0;
	while (i < len)
	{
		node = stack_pop(&state->a);
		nums[i++] = *((int *) node->content);
	}
	return (nums);
}
