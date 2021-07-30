#include "philosophers.h"

static void	ft_print_err(t_exit_code exit_code);

void	ft_exit_error(t_data *data, t_exit_code exit_code)
{
	ft_print_err(exit_code);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	ft_print_err(t_exit_code exit_code)
{
	if (exit_code == WRONG_ARGUMENT_NB)
		printf("Error: Wrong number of arguments\n");
	else if (exit_code == WRONG_ARGUMENT_TYPE)
		printf("Error: Arguments must be positive integers\n");
	else
		printf("Error: Unknown error\n");
}
