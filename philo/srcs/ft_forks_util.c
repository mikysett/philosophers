#include "philosophers.h"

static bool	ft_set_busy_forks(pthread_mutex_t *busy_forks_mutex,
				bool *is_fork_right_busy, bool *is_fork_left_busy);

bool	ft_take_forks(t_philo *philo,
			pthread_mutex_t *fork_right, pthread_mutex_t *fork_left)
{
	if (ft_set_busy_forks(philo->busy_forks_mutex,
			philo->is_fork_right_busy, philo->is_fork_left_busy))
	{
		philo->state = fork_taken;
		if (pthread_mutex_lock(fork_right) != 0)
			ft_exit_error(NULL, MUTEX_LOCK_FAIL);
		ft_print_philo_state(philo);
		if (pthread_mutex_lock(fork_left) != 0)
			ft_exit_error(NULL, MUTEX_LOCK_FAIL);
		ft_print_philo_state(philo);
		return (true);
	}
	return (false);
}

static bool	ft_set_busy_forks(pthread_mutex_t *busy_forks_mutex,
	bool *is_fork_right_busy, bool *is_fork_left_busy)
{
	bool	is_success;

	if (pthread_mutex_lock(busy_forks_mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	if (!*is_fork_right_busy && !*is_fork_left_busy)
	{
		*is_fork_right_busy = true;
		*is_fork_left_busy = true;
		is_success = true;
	}
	else
		is_success = false;
	if (pthread_mutex_unlock(busy_forks_mutex) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	return (is_success);
}

void	ft_release_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->fork_right) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	if (pthread_mutex_unlock(philo->fork_left) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	if (pthread_mutex_lock(philo->busy_forks_mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	*(philo->is_fork_right_busy) = false;
	*(philo->is_fork_left_busy) = false;
	if (pthread_mutex_unlock(philo->busy_forks_mutex) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
}
