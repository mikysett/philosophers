#include "philosophers.h"

pthread_mutex_t	*ft_init_forks(int nb_forks)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * nb_forks);
	if (!forks)
		ft_exit_error(NULL, MEMORY_FAIL);
	while (i < nb_forks)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
			ft_exit_error(NULL, MUTEX_FAIL);
		i++;
	}
	return (forks);
}

pthread_mutex_t	*ft_init_busy_forks_mutex(void)
{
	pthread_mutex_t	*busy_forks_mutex;

	busy_forks_mutex = malloc(sizeof(pthread_mutex_t));
	if (!busy_forks_mutex)
		ft_exit_error(NULL, MEMORY_FAIL);
	if (pthread_mutex_init(busy_forks_mutex, NULL) != 0)
		ft_exit_error(NULL, MUTEX_FAIL);
	return (busy_forks_mutex);
}

pthread_mutex_t	*ft_init_a_philo_died_mutex(void)
{
	pthread_mutex_t	*a_philo_died_mutex;

	a_philo_died_mutex = malloc(sizeof(pthread_mutex_t));
	if (!a_philo_died_mutex)
		ft_exit_error(NULL, MEMORY_FAIL);
	if (pthread_mutex_init(a_philo_died_mutex, NULL) != 0)
		ft_exit_error(NULL, MUTEX_FAIL);
	return (a_philo_died_mutex);
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
