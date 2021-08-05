#include "philosophers.h"

void	ft_init_printer_mutex(t_data *data)
{
	data->printer_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->printer_mutex)
		ft_exit_error(NULL, MEMORY_FAIL);
	if (pthread_mutex_init(data->printer_mutex, NULL) != 0)
		ft_exit_error(NULL, MUTEX_FAIL);
}

void	ft_print_philo_state(t_philo *philo)
{
	static char	action_str[5][100] = {
			"has taken a fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"
		};

	if (pthread_mutex_lock(philo->printer_mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
	if (!ft_a_philo_died(NULL, philo->a_philo_died_mutex))
		printf("%.5d %d %s\n",
			ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv()),
			philo->id,
			action_str[philo->state]);
	if (philo->state == dead)
		ft_a_philo_died(true, philo->a_philo_died_mutex);
	if (pthread_mutex_unlock(philo->printer_mutex) != 0)
		ft_exit_error(NULL, MUTEX_UNLOCK_FAIL);
}
