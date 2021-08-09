#include "philosophers.h"

static bool	ft_set_busy_forks(t_philo *philo);

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
	bool	forks_taken;

	forks_taken = false;
	ft_lock_mutex(philo->forks_mutex);
	if (*(philo->is_fork_left_busy) == false
		&& *(philo->is_fork_right_busy) == false)
	{
		*(philo->is_fork_left_busy) = true;
		*(philo->is_fork_right_busy) = true;
		forks_taken = true;
	}
	ft_unlock_mutex(philo->forks_mutex);
	return (forks_taken);
}

void	ft_release_forks(t_philo *philo)
{
	ft_lock_mutex(philo->forks_mutex);
	*(philo->is_fork_left_busy) = false;
	*(philo->is_fork_right_busy) = false;
	ft_unlock_mutex(philo->forks_mutex);
}
