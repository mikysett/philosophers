#include "philosophers.h"

static bool	ft_set_busy_forks(t_philo *philo,
				pthread_mutex_t *fork_right, pthread_mutex_t *fork_left);

bool	ft_take_forks(t_philo *philo)
{
	if (ft_set_busy_forks(philo, philo->fork_right, philo->fork_left))
	{
		philo->state = fork_taken;
		ft_print_philo_state(philo);
		ft_print_philo_state(philo);
		return (true);
	}
	return (false);
}

static bool	ft_set_busy_forks(t_philo *philo,
				pthread_mutex_t *fork_right, pthread_mutex_t *fork_left)
{
	bool	right_fork_taken;
	bool	left_fork_taken;

	right_fork_taken = false;
	left_fork_taken = false;
	if (pthread_mutex_lock(fork_right) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	if (*(philo->is_fork_right_busy) == false)
	{
		*(philo->is_fork_right_busy) = true;
		right_fork_taken = true;
	}
	if (pthread_mutex_unlock(fork_right) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);

	if (right_fork_taken)
	{
		if (pthread_mutex_lock(fork_left) != 0)
			ft_exit_error(NULL, MUTEX_LOCK_FAIL);
		if (*(philo->is_fork_left_busy) == false)
		{
			*(philo->is_fork_left_busy) = true;
			left_fork_taken = true;
		}
		if (pthread_mutex_unlock(fork_left) != 0)
			ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
	}
	else
		return (false);

	if (right_fork_taken && !left_fork_taken)
	{
		ft_release_fork(philo->fork_right, philo->is_fork_right_busy);
		return (false);
	}
	return (true);
}

void	ft_release_fork(pthread_mutex_t *fork, bool *is_fork_busy)
{
	if (pthread_mutex_lock(fork) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	*is_fork_busy = false;
	if (pthread_mutex_unlock(fork) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
}

// void	ft_release_forks(t_philo *philo)
// {
// 	if (pthread_mutex_lock(philo->fork_right) != 0)
// 		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
// 	if (pthread_mutex_lock(philo->fork_left) != 0)
// 		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
// 	*(philo->is_fork_right_busy) = false;
// 	*(philo->is_fork_left_busy) = false;
// 	if (pthread_mutex_unlock(philo->fork_right) != 0)
// 		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
// 	if (pthread_mutex_unlock(philo->fork_left) != 0)
// 		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
// }
