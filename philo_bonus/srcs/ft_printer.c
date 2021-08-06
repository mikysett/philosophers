#include "philosophers.h"

void	ft_print_philo_state(t_philo *philo)
{
	static char	action_str[5][100] = {
			"has taken a fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"
		};

	if (sem_wait(philo->printer) != 0)
		ft_exit_error(NULL, SEM_LOCK_FAIL);
	printf("%.5d %d %s\n",
		ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv()),
		philo->id,
		action_str[philo->state]);
	if (philo->state != dead)
		if (sem_post(philo->printer) != 0)
			ft_exit_error(NULL, SEM_UNLOCK_FAIL);
}
