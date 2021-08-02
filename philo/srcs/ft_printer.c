#include "philosophers.h"

void	ft_init_printer_mutex(t_data *data)
{
	if (pthread_mutex_init(&(data->printer_mutex), NULL) != 0)
		ft_exit_error(NULL, MUTEX_FAIL);
}

void	ft_print_philo_state_or_kill(t_philo *philo)
{
	static char	action_str[5][100] = {
			"has taken a fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"
		};
	static bool	a_philo_died = false;

	if (pthread_mutex_lock(philo->printer_mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	if (a_philo_died == true)
		exit(EXIT_SUCCESS);
	printf("%.5d %d %s\n",
		ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv()),
		philo->id,
		action_str[philo->state]);
	if (philo->state == dead)
		a_philo_died = true;
	if (pthread_mutex_unlock(philo->printer_mutex) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
}
