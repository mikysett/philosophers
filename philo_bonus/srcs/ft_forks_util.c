#include "philosophers.h"

static bool	ft_set_busy_forks(int *nb_free_forks);

void	*ft_take_forks(void *philo_void)
{
	t_philo	*philo;

	// printf("take forks pthread\n");
	philo = (t_philo *)philo_void;
	while (1)
	{
		// printf("p%d try to take a fork\n", philo->id);
		if (sem_wait(philo->forks) != 0)
			ft_exit_error(NULL, SEM_LOCK_FAIL);
		philo->forks_in_hand++;
		// printf("p%d taking a fork\n", philo->id);
		// printf("IN TAKE FORKS: p%d forks in hand: %d\n", philo->id, philo->forks_in_hand);
		if (philo->forks_in_hand == 2)
			break ;
	}
	philo->state = fork_taken;
	ft_print_philo_state(philo);
	ft_print_philo_state(philo);
	return (NULL);
}

// bool	ft_take_forks(t_philo *philo)
// {
// 	// printf("p%d set busy fork fork\n", philo->id);
// 	if (ft_set_busy_forks(philo->nb_free_forks))
// 	{
// 		// printf("p%d take forks\n", philo->id);
// 		// printf("nb_free_forks pointer: %p\n", philo->nb_free_forks);
// 		// printf("nb_free_forks value  : %d\n\n", *(philo->nb_free_forks));
// 		philo->state = fork_taken;
// 		if (sem_wait(philo->forks) != 0)
// 			ft_exit_error(NULL, SEM_LOCK_FAIL);
// 		ft_print_philo_state(philo);
// 		if (sem_wait(philo->forks) != 0)
// 			ft_exit_error(NULL, SEM_LOCK_FAIL);
// 		ft_print_philo_state(philo);
// 		return (true);
// 	}
// 	return (false);
// }

static bool	ft_set_busy_forks(int *nb_free_forks)
{
	// if (*nb_free_forks >= 2)
	// {
	// 	*nb_free_forks -= 2;
	// 	return (true);
	// }
	return (true);
}

void	ft_release_forks(t_philo *philo)
{
	if (sem_post(philo->forks) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
	if (sem_post(philo->forks) != 0)
		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
	philo->forks_in_hand = 0;
}
