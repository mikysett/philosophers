#include "philosophers.h"

void	*ft_philo_thread(void *philo_void)
{
	t_philo	*philo = (t_philo *)philo_void;
	int		curr_time;

	while (philo->state != dead && !ft_eaten_enough(philo))
	{
		curr_time = ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		if (ft_starved(philo, curr_time))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(philo, curr_time);
		else if (philo->state == eating)
			ft_do_sleep(philo);
		else if (philo->state == sleeping)
			ft_do_think(philo);
	}
	return (philo_void);
}

bool	ft_eaten_enough(t_philo *philo)
{
	if (philo->nb_meals == philo->timings.nb_times_to_eat)
		return (true);
	return (false);
}

bool	ft_starved(t_philo *philo, int curr_time)
{
	if (curr_time - philo->last_eat_ts >= philo->timings.time_to_die)
		return (true);
	return (false);
}

void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_philo_state(philo);
}

void	ft_try_eat(t_philo *philo, int curr_time)
{
	if (ft_forks_taken(philo))
	{
		philo->state = eating;
		ft_print_philo_state(philo);
		philo->last_eat_ts = curr_time;
		usleep(philo->timings.time_to_eat);
		// TODO check if there is enough time before to die
		philo->nb_meals++;
	}
}

void	ft_do_sleep(t_philo *philo)
{
		philo->state = sleeping;
		ft_print_philo_state(philo);
		ft_release_forks(philo);
		//TODO check if there is enough time before to die
		usleep(philo->timings.time_to_sleep);
}

void	ft_do_think(t_philo *philo)
{
		philo->state = thinking;
		ft_print_philo_state(philo);
}
