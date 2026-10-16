/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:56:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/16 12:03:12 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "../parser/parser.h"
# include "../stacker/stacker.h"
# include "../analyzer/analyzer.h"
# include "../bench/bench.h"
# include "../../libft/libft.h"

void	do_operation(char *op, t_state *state);
void	solve_sorting(t_state *state, t_config *config);
void	solve_two(t_state *state);
void	solve_three(t_state *state);

void	bubble_sort(t_state *state, int size, int in_stack_a);
void	solve_medium(t_state *state, int size, int in_stack_a);
void	merge_sort(t_state *state, int size, int in_stack_a);

#endif
