#include "philosophers.h"

void	ft_free_data(t_data *data)
{
	if (data)
	{
		free(data->philo_pids);
		free(data->philo);
	}
}

void	*ft_malloc_or_exit(int size)
{
	void	*malloc_result;

	malloc_result = malloc(size);
	if (!malloc_result)
		ft_exit_error(NULL, MEMORY_FAIL);
	return (malloc_result);
}
