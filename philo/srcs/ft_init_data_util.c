#include "philosophers.h"

pthread_mutex_t	*ft_init_forks(int nb_forks)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = ft_malloc_or_exit(sizeof(pthread_mutex_t) * nb_forks);
	while (i < nb_forks)
	{
		ft_init_mutex(forks + i);
		i++;
	}
	return (forks);
}

void	ft_set_forks_in_philo(t_philo *philo, t_data *data, int i)
{
	int		prev_fork;

	prev_fork = previous(i, data->nb_philo);
	philo[i].fork_right = &data->forks[i];
	philo[i].fork_left = &data->forks[prev_fork];
	philo[i].is_fork_right_busy = &data->is_fork_busy[i];
	philo[i].is_fork_left_busy = &data->is_fork_busy[prev_fork];
}
