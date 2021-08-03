#include "philosophers.h"

static bool	ft_set_busy_forks(bool *is_fork_right_busy,
				bool *is_fork_left_busy);

bool	ft_take_forks(t_philo *philo,
			pthread_mutex_t *fork_right, pthread_mutex_t *fork_left)
{
	if (ft_set_busy_forks(philo->is_fork_right_busy,
			philo->is_fork_left_busy))
	{
		philo->state = fork_taken;
		if (pthread_mutex_lock(fork_right) != 0)
		{
			printf("philo id: %d\n", philo->id);
			ft_exit_error(NULL, MUTEX_LOCK_FAIL);
		}
		ft_print_philo_state_or_kill(philo);
		if (pthread_mutex_lock(fork_left) != 0)
		{
			printf("fork left philo id: %d\n", philo->id);
			ft_exit_error(NULL, MUTEX_LOCK_FAIL);
		}
		ft_print_philo_state_or_kill(philo);
		return (true);
	}
	return (false);
}

static bool	ft_set_busy_forks(bool *is_fork_right_busy,
	bool *is_fork_left_busy)
{
	if (!*is_fork_right_busy && !*is_fork_left_busy)
	{
		*is_fork_right_busy = true;
		*is_fork_left_busy = true;
		return (true);
	}
	return (false);
}

void	ft_release_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->fork_right) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	if (pthread_mutex_unlock(philo->fork_left) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	*(philo->is_fork_right_busy) = false;
	*(philo->is_fork_left_busy) = false;
}
