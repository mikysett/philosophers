#include "philosophers.h"

void	ft_catch_results(t_data *data)
{
	int		i;
	t_philo	*curr_philo;

	i = 0;
	curr_philo = NULL;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo_threads[i], (void **)&curr_philo) != 0)
			ft_exit_error(data, THREAD_JOIN_FAIL);
		i++;
	}
}
