#include "philosophers.h"

static void	ft_free_forks(sem_t *forks);

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_forks(data->forks);
		// free(data->printer_mutex);
		free(data->philo_pids);
		free(data->philo);
	}
}

static void	ft_free_forks(sem_t *forks)
{
	if (sem_close(forks) != 0)
		ft_exit_error(NULL, SEMAPHORE_FAIL);
	// int	i;

	// i = 0;
	// while (i < data->nb_philo)
	// {
	// 	if (is_fork_busy[i] == false)
	// 	{
	// 		if (pthread_mutex_destroy(&data->forks[i]) != 0)
	// 			ft_exit_error(NULL, MUTEX_DESTROY_FAIL);
	// 	}
	// 	i++;
	// }
	// free(data->forks);
}

pid_t	*ft_init_philo_pids(int nb_philo)
{
	pid_t	*philo_pids;

	philo_pids = malloc(sizeof(pid_t) * nb_philo);
	if (!philo_pids)
		ft_exit_error(NULL, MEMORY_FAIL);
	return (philo_pids);
}
