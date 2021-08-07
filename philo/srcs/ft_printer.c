#include "philosophers.h"

void	ft_init_printer_mutex(t_data *data)
{
	data->printer_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->printer_mutex)
		ft_exit_error(NULL, MEMORY_FAIL);
	ft_init_mutex(data->printer_mutex);
}

void	ft_print_state_or_kill(t_philo *philo)
{
	static char	action_str[5][100] = {
			"has taken a fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"
		};
	static bool	a_philo_died = false;

	ft_lock_mutex(philo->printer_mutex);
	if (a_philo_died == false)
		printf("%.5d %d %s\n",
			ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv()),
			philo->id,
			action_str[philo->state]);
	else
		philo->state = dead;
	if (philo->state == dead)
		a_philo_died = true;
	ft_unlock_mutex(philo->printer_mutex);
}
