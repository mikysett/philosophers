#include "philosophers.h"

void	ft_start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				ft_philo_thread, (void *)&data->philo[i]) != 0)
			ft_exit_error(data, THREAD_CREATE_FAIL);
		i++;
	}
}
