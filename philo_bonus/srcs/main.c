#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = ft_init_data(argc, argv);
	ft_start_philosophers(&data);
	ft_catch_results(&data);
	ft_free_data(&data);
	return (EXIT_SUCCESS);
}
