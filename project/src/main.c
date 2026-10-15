/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:37:08 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/15 02:45:08 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stacker.h"
#include "analyzer.h"
#include "bench.h"

/* Dummy deleter for ft_lstclear when nodes don't own their content */
static void	do_nothing(void *c)
{
	(void)c;
}

/* Aux function for testing bench mode */
static void	run_benhcmark(const t_analysis *analysis)
{
	t_bench		bench;

	bench_init(&bench);
	bench_record(&bench, sa);
	bench_record(&bench, pb);
	bench_record(&bench, ra);
	bench_record(&bench, rra);
	print_benchmark(analysis, &bench);
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
	if (config.bench)
		run_benhcmark(&analysis);
	free_state(&state, &do_nothing);
	free_config(&config);
	return (0);
}
