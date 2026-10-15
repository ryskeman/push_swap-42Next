/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:56:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/15 18:44:38 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "../parser/parser.h"
# include "../stacker/stacker.h"
# include "../analyzer/analyzer.h"
# include "../../libft/libft.h"

void	do_operation(char *op, t_state *state);
void	solve_sorting(t_state *state, t_config *config);

void	bubble_sort(t_state *state, int size);
void	solve_medium(t_state *state, int size);
void	solve_complex(t_state *state, int size);

#endif
