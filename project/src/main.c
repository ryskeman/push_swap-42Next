/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:37:08 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 19:52:17 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stacker.h"
#include "analyzer.h"

/* Dummy deleter for ft_lstclear when nodes don't own their content */
static void	do_nothing(void *c)
{
	(void)c;
}

/* Main function */
int	main(int ac, char **av)
{
	t_config	config;
	t_analysis	analysis;
	t_state		state;

	if (ac < 2)
		return (0);
	if (!parsing_input(ac, av, &config))
		return (write(2, "Error\n", 6), 1);
	if (!analyze_input(&config, &analysis))
		return (free_config(&config), write(2, "Error\n", 6), 1);
	if (analysis.disorder == 0)
		return (free_config(&config), 0);
	fill_state(config.numbers, config.size, &state);
	free_state(&state, &do_nothing);
	free_config(&config);
	return (0);
}
