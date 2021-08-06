#include "philosophers.h"

void	*ft_take_forks(void *philo_void)
{
	t_philo	*philo;
	int		taken_forks;

	philo = (t_philo *)philo_void;
	taken_forks = 0;
	while (taken_forks != 2)
	{
		if (sem_wait(philo->forks) != 0)
			ft_exit_error(NULL, SEM_LOCK_FAIL);
		taken_forks++;
	}
	ft_set_forks_in_hand(philo, taken_forks);
	return (NULL);
}

void	ft_release_forks(t_philo *philo)
{
	if (sem_post(philo->forks) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
	if (sem_post(philo->forks) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
	ft_set_forks_in_hand(philo, 0);
}

int	ft_get_forks_in_hand(t_philo *philo)
{
	int	forks_in_hand;
	if (sem_wait(philo->read_forks_in_hand) != 0)
		ft_exit_error(NULL, SEM_LOCK_FAIL);
	forks_in_hand = philo->forks_in_hand;
	if (sem_post(philo->read_forks_in_hand) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
	return (forks_in_hand);
}

void	ft_set_forks_in_hand(t_philo *philo, int new_forks_in_hand)
{
	if (sem_wait(philo->read_forks_in_hand) != 0)
		ft_exit_error(NULL, SEM_LOCK_FAIL);
	philo->forks_in_hand = new_forks_in_hand;
	if (sem_post(philo->read_forks_in_hand) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
}
