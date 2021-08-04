#include "philosophers.h"

bool	ft_eaten_enough(t_philo *philo)
{
	if (philo->timings.nb_times_to_eat != EAT_FOREVER
		&& philo->nb_meals >= philo->timings.nb_times_to_eat)
		return (true);
	return (false);
}

bool	ft_starved(t_philo *philo, int curr_time)
{
	if (curr_time - philo->last_eat_ts >= philo->timings.time_to_die)
		return (true);
	return (false);
}

int	ft_max_time_before_dying_in_ms(t_philo *philo,
		int curr_time, int time_to_wait)
{
	const int	time_before_dying = philo->timings.time_to_die
					- (curr_time - philo->last_eat_ts);

	if (time_before_dying < time_to_wait)
		return (time_before_dying * 1000);
	return (time_to_wait * 1000);
}

bool	ft_a_philo_died(bool set_death)
{
	static bool	a_philo_died = false;

	if (set_death)
		a_philo_died = true;
	return (a_philo_died);
}
