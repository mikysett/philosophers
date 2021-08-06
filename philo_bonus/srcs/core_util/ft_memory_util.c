#include "philosophers.h"

void	ft_free_data(t_data *data)
{
	if (data)
	{
		free(data->philo_pids);
		free(data->philo);
	}
}

pid_t	*ft_init_philo_pids(int nb_philo)
{
	pid_t	*philo_pids;

	philo_pids = malloc(sizeof(pid_t) * nb_philo);
	if (!philo_pids)
		ft_exit_error(NULL, MEMORY_FAIL);
	return (philo_pids);
}
