#include "philosophers.h"

void	ft_print_philo(t_philo *philo)
{
	static char	state_str[5][100] = {
			"fork_taken",
			"eating",
			"sleeping",
			"thinking",
			"dead"
		};

	printf("\n");
	printf("philo id: %d\n", philo->id);
	printf("nb_meals: %d\n", philo->nb_meals);
	printf("state   : %s\n\n", state_str[philo->state]);
}

void	ft_catch_results(t_data *data)
{
	int		i;
	t_philo	*curr_philo;

	i = 0;
	curr_philo = NULL;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo_threads[i], (void **)&curr_philo) != 0)
			ft_exit_error(data, THREAD_JOIN_FAIL);
		i++;
	}
}
