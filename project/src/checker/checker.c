/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:58:09 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 18:07:10 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_nothing(void *c)
{
	(void) c;
}

int	soft_exit(t_config *config, t_state *state, int *nums)
{
	if (config)
		free_config(config);
	if (state)
		free_state(state, &do_nothing);
	if (nums)
		free(nums);
	ft_putstr_fd("Error", 2);
	return (1);
}

int	perform_operations(t_state *state)
{
	char		*line;
	t_operation	op;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		op = get_operation(line);
		free(line);
		if (op == -1)
			return (0);
		stack_operate(op, state);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			disorder;
	int			*nums;
	t_config	config;
	t_state		state;

	nums = NULL;
	if (!parsing_input(argc, argv, &config))
		return (soft_exit(&config, &state, nums));
	fill_state(config.numbers, config.size, &state);
	if (!perform_operations(&state))
		return (soft_exit(&config, &state, nums));
	nums = export_state(&state);
	disorder = get_disorder(nums, config.size);
	if (disorder == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (soft_exit(&config, &state, nums), 0);
}
