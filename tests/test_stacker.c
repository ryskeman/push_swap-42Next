#include "../project/stacker/stacker.h"

void	print_num(void *n)
{
	char	*str;

	str = ft_itoa(*((int *) n));
	ft_putstr_fd(", ", 1);
	ft_putstr_fd(str, 1);
}

void	stack_print(t_list *stack)
{
	ft_lstiter(stack, &print_num);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_list	*st;
	int		nums[6] = {0, 1, 2, 3, 4, 5};

	st = stack_create(nums, 6);
	stack_print(st);

	swap(&st);
	stack_print(st);

	rotate(&st);
	stack_print(st);

	swap(&st);
	stack_print(st);

	reverse_rotate(&st);
	stack_print(st);
}
