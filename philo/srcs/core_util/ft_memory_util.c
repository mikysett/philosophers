#include "philosophers.h"

void	ft_free_data(t_data *data)
{
	if (data)
	{
		free(data->philo);
	}
}
