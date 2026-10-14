#include "../project/src/stacker/stacker.h"

void	print_num(void *n)
{
	char	*str;

	str = ft_itoa(*((int *) n));
	ft_putstr_fd(", ", 1);
	ft_putstr_fd(str, 1);
}

void	stacks_print(t_list **stacks)
{
	ft_putstr_fd("a: ", 1);
	ft_lstiter(stacks[0], &print_num);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b: ", 1);
	ft_lstiter(stacks[1], &print_num);
	ft_putstr_fd("\n\n", 1);
}

int	main(void)
{
	t_list	**sts;
	int		nums[6] = {0, 1, 2, 3, 4, 5};

	sts = create_stacks(nums, 6);
	stacks_print(sts);

	stack_operate(sa, sts);
	stacks_print(sts);

	stack_operate(ra, sts);
	stacks_print(sts);

	stack_operate(sa, sts);
	stacks_print(sts);

	stack_operate(rra, sts);
	stacks_print(sts);

	stack_operate(pb, sts);
	stacks_print(sts);

	stack_operate(pb, sts);
	stacks_print(sts);

	stack_operate(sb, sts);
	stacks_print(sts);

	stack_operate(pa, sts);
	stacks_print(sts);

	stack_operate(pa, sts);
	stacks_print(sts);
}
