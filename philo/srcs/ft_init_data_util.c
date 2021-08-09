#include "philosophers.h"

pthread_mutex_t	*ft_init_forks_mutex(void)
{
	pthread_mutex_t	*forks_mutex;

	forks_mutex = ft_malloc_or_exit(sizeof(pthread_mutex_t));
	ft_init_mutex(forks_mutex);
	return (forks_mutex);
}

void	ft_set_forks_in_philo(t_philo *philo, t_data *data, int i)
{
	int		prev_fork;

	prev_fork = previous(i, data->nb_philo);
	philo[i].forks_mutex = data->forks_mutex;
	philo[i].is_fork_right_busy = &data->is_fork_busy[i];
	philo[i].is_fork_left_busy = &data->is_fork_busy[prev_fork];
}
