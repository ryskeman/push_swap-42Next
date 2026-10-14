#include "../project/src/stacker/stacker.h"

void	print_num(void *n)
{
	char	*str;

	str = ft_itoa(*((int *) n));
	ft_putstr_fd(", ", 1);
	ft_putstr_fd(str, 1);
}

void	print_state(t_state state)
{
	ft_putstr_fd("a: ", 1);
	ft_lstiter(state.a, &print_num);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b: ", 1);
	ft_lstiter(state.b, &print_num);
	ft_putstr_fd("\n\n", 1);
}

void	print_nums(int *nums, int len)
{
	int	i = 0;
	while (i < len)
		print_num(&nums[i++]);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_state	state;
	int		size = 6;
	int		nums[6] = {0, 1, 2, 3, 4, 5};

	fill_state(nums, size, &state);
	print_state(state);

	stack_operate(sa, &state);
	print_state(state);

	stack_operate(ra, &state);
	print_state(state);

	stack_operate(sa, &state);
	print_state(state);

	stack_operate(rra, &state);
	print_state(state);

	stack_operate(pb, &state);
	print_state(state);

	stack_operate(pb, &state);
	print_state(state);

	stack_operate(sb, &state);
	print_state(state);

	stack_operate(pa, &state);
	print_state(state);

	stack_operate(pa, &state);
	print_state(state);

	int	*nums2 = export_state(&state);
	print_nums(nums2, size);
}
