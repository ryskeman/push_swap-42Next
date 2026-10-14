/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:37:08 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 17:07:31 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stacker.h"
#include "analyzer.h"

/* Function to free nodes memory */
static void	free_stack_nodes(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

/* Main function */
int	main(int ac, char **av)
{
	t_config	config;
	t_analysis	analysis;
	t_list		*stack_a;

	if (ac < 2)
		return (0);
	if (!parsing_input(ac, av, &config))
		return (write(2, "Error\n", 6), 1);
	if (!analyze_input(&config, &analysis))
		return (free_config(&config), write(2, "Error\n", 6), 1);
	if (analysis.disorder == 0)
		return (free_config(&config), 0);
	stack_a = stack_create(config.numbers, config.size);
	if (!stack_a)
		return (free_config(&config), write(2, "Error\n", 6), 1);
	free_stack_nodes(&stack_a);
	free_config(&config);
	return (0);
}
