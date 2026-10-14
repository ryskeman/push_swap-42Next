#include <stdio.h>
#include "../project/analyzer/analyzer.h"

static void	test_case(const char *label, const int *arr, int size)
{
	int	disorder;

	disorder = get_disorder(arr, size);
	printf("%-18s: %5d  -> %3d.%02d%%\n",
		label, disorder, disorder / 100, disorder % 100);
}

int	main(void)
{
	int	sorted[4] = {1, 2, 3, 4};
	int	one_inv[4] = {1, 3, 2, 4};
	int	reversed[4] = {4, 3, 2, 1};
	int	empty[1] = {42};

	test_case("Ordenado (0 inv)", sorted, 4);
	test_case("1 inv (16.67%)", one_inv, 4);
	test_case("Invertido (100%)", reversed, 4);
	test_case("1 elemento", empty, 1);
	test_case("Array nulo", NULL, 0);
	return (0);
}
