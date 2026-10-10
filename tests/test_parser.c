#include <stdio.h>
#include "../project/parser/parser.h"

int	main(int argc, char **argv)
{
	t_config	cfg;
	int			res;
	int			i;

	if (argc == 1)
		return (0);
	res = parsing_input(argc, argv, &cfg);
	if (!res)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("--- PARSER RESULT ---\n");
	printf("Strategy: %d (0:Adapt, 1:Simple, 2:Medium, 3:Complex)\n", cfg.strategy);
	printf("Benchmark: %s\n", cfg.bench ? "ON" : "OFF");
	printf("Total numbers: %d\n", cfg.size);
	printf("Numbers: ");
	i = 0;
	while (i < cfg.size)
	{
		printf("[%d] ", cfg.numbers[i]);
		i++;
	}
	printf("\n---------------------\n");
	free_config(&cfg);
	return (0);
}
