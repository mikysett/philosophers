#include "philosophers.h"

pthread_mutex_t	*ft_init_printer_mutex(void)
{
	pthread_mutex_t	*printer_mutex;

	printer_mutex = malloc(sizeof(pthread_mutex_t));
	if (!printer_mutex)
		ft_exit_error(NULL, MEMORY_FAIL);
	ft_init_mutex(printer_mutex);
	return (printer_mutex);
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
		printf("%lld %d %s\n",
			ft_delta_tv_in_us(philo->timings.start_time, ft_get_tv()) / 1000,
			philo->id,
			action_str[philo->state]);
	if (philo->state == dead)
		a_philo_died = true;
	if (a_philo_died)
		philo->state = dead;
	ft_unlock_mutex(philo->printer_mutex);
}
