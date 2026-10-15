/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:36:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/15 19:05:11 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	swap_values(t_state *state)
{
	do_operation("pa\n", state);
	do_operation("ra\n", state);
	do_operation("pb\n", state);
}

void	bubble_sort(t_state *state, int size)
{
	int	n;
	int	i;

	n = size;
	while (n > 1)
	{
		i = 0;
		do_operation("pb\n", state);
		while (i < n)
		{
			if (*((int *) state->a->content) < *((int *) state->b->content))
				swap_values(state);
			else
				do_operation("ra\n", state);
			i++;
		}
		n--;
	}
	while (n < size)
	{
		do_operation("pa\n", state);
		n++;
	}
}
