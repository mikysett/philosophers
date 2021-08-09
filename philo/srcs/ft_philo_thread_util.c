#include "philosophers.h"

bool	ft_eaten_enough(t_philo *philo)
{
	if (philo->timings.nb_times_to_eat != EAT_FOREVER
		&& philo->nb_meals >= philo->timings.nb_times_to_eat)
		return (true);
	return (false);
}

bool	ft_starved(t_philo *philo)
{
	if (ft_delta_tv_in_us(philo->last_eat_tv, ft_get_tv())
		>= philo->timings.time_to_die_us)
		return (true);
	return (false);
}

int	ft_max_time_before_dying_in_us(t_philo *philo, int time_to_wait_in_us)
{
	const long long	time_before_dying_in_us = philo->timings.time_to_die_us
					- ft_delta_tv_in_us(philo->last_eat_tv, ft_get_tv());

	if (time_before_dying_in_us < time_to_wait_in_us)
		return (time_before_dying_in_us);
	return (time_to_wait_in_us);
}
