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
	static bool	a_philo_died = false;

	if (a_philo_died)
		return ;
	printf("%d %d %s\n",
		ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv()),
		philo->id,
		action_str[philo->state]);
	if (philo->state == dead)
		a_philo_died = true;
}