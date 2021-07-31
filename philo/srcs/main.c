#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = ft_init_data(argc, argv);
	ft_free_data(&data);
	return (EXIT_SUCCESS);
}
