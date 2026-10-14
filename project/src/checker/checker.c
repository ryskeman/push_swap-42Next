/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:58:09 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 15:01:20 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	soft_exit(void)
{
	ft_putstr_fd("Error", 2);
	return (1);
}

t_operation	get_operation(char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		return (sa);
	return (-1);
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
		if (op == -1)
			return (free(line), 0);
		stack_operate(op, state);
	}
	return (free(line), 1);
}

int	main(int argc, char **argv)
{
	int			ok;
	int			disorder;
	int			*nums;
	t_config	config;
	t_state		state;

	ok = parsing_input(argc, argv, &config);
	if (!ok)
		return (soft_exit());
	fill_state(config.numbers, config.size, &state);
	ok = perform_operations(&state);
	if (!ok)
		return (soft_exit());
	nums = export_state(&state);
	disorder = get_disorder(nums, config.size);
	if (disorder > 0)
		ft_putstr_fd("KO", 1);
	else
		ft_putstr_fd("OK", 1);
}
