#include "philosophers.h"

static bool	ft_set_busy_forks(t_philo *philo);
static bool	ft_take_single_fork(pthread_mutex_t *fork, bool *is_fork_busy);

bool	ft_take_forks(t_philo *philo)
{
	if (ft_set_busy_forks(philo))
	{
		philo->state = fork_taken;
		ft_print_state_or_kill(philo);
		ft_print_state_or_kill(philo);
		return (true);
	}
	return (false);
}

static bool	ft_set_busy_forks(t_philo *philo)
{
	if (ft_take_single_fork(philo->fork_right, philo->is_fork_right_busy))
	{
		if (ft_take_single_fork(philo->fork_left, philo->is_fork_left_busy))
			return (true);
		else
			ft_release_fork(philo->fork_right, philo->is_fork_right_busy);
		return (false);
	}
	else
		return (false);
}

static bool	ft_take_single_fork(pthread_mutex_t *fork, bool *is_fork_busy)
{
	bool	fork_taken;

	fork_taken = false;
	ft_lock_mutex(fork);
	if (*(is_fork_busy) == false)
	{
		*(is_fork_busy) = true;
		fork_taken = true;
	}
	ft_unlock_mutex(fork);
	return (fork_taken);
}

void	ft_release_fork(pthread_mutex_t *fork, bool *is_fork_busy)
{
	ft_lock_mutex(fork);
	*is_fork_busy = false;
	ft_unlock_mutex(fork);
}
