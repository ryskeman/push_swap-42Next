/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:24:46 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/16 14:13:55 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "bench.h"

void	do_operation(char *op, t_state *state)
{
	t_operation	operation;

	operation = get_operation(op);
	stack_operate(operation, state);
	ft_printf("%s", op);
	if (state && state->bench)
		bench_record(state->bench, operation);
}

void	solve_medium(t_state *state, int size)
{
	// SOLUCION DUMMY PROVISIONAL
	bubble_sort(state, size);
}

void	solve_sorting(t_state *state, t_config *config)
{
	if (config->size <= 1)
		return ;
	if (config->size == 2)
		return (solve_two(state));
	if (config->size == 3)
		return (solve_three(state));
	if (config->strategy == STRAT_SIMPLE)
		return (bubble_sort(state, config->size));
	if (config->strategy == STRAT_MEDIUM)
		return (solve_medium(state, config->size));
	if (config->strategy == STRAT_COMPLEX)
		return (merge_sort(state, config->size));
}
