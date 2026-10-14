/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:56:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 17:19:01 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

void	fill_state(int *nums, int len, t_state *state)
{
	state->a = stack_create(nums, len);
	state->b = stack_create(NULL, 0);
}

void	free_state(t_state *state, void (*del)(void *))
{
	if (!state)
		return ;
	if (state->a)
		ft_lstclear(&state->a, del);
	state->a = NULL;
	if (state->b)
		ft_lstclear(&state->b, del);
	state->b = NULL;
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

t_operation	get_operation(char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		return (sa);
	if (ft_strncmp(op, "sb", 2) == 0)
		return (sb);
	if (ft_strncmp(op, "ss", 2) == 0)
		return (ss);
	if (ft_strncmp(op, "pa", 2) == 0)
		return (pa);
	if (ft_strncmp(op, "pb", 2) == 0)
		return (pb);
	if (ft_strncmp(op, "ra", 2) == 0)
		return (ra);
	if (ft_strncmp(op, "rb", 2) == 0)
		return (rb);
	if (ft_strncmp(op, "rr", 2) == 0)
		return (rr);
	if (ft_strncmp(op, "rra", 3) == 0)
		return (rra);
	if (ft_strncmp(op, "rrb", 3) == 0)
		return (rrb);
	if (ft_strncmp(op, "rrr", 3) == 0)
		return (rrr);
	return (-1);
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
