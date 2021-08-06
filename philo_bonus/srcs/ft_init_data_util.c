#include "philosophers.h"

sem_t	*ft_init_forks(int nb_forks)
{
	sem_t	*forks;

	sem_unlink("philo_forks");
	forks = sem_open("philo_forks", O_CREAT, 0644, nb_forks);
	if (forks == SEM_FAILED)
		ft_exit_error(NULL, SEMAPHORE_FAIL);
	return (forks);
}

sem_t	*ft_init_printer(void)
{
	sem_t	*printer;

	sem_unlink("philo_printer");
	printer = sem_open("philo_printer", O_CREAT, 0644, 1);
	if (printer == SEM_FAILED)
		ft_exit_error(NULL, SEMAPHORE_FAIL);
	return (printer);
}
