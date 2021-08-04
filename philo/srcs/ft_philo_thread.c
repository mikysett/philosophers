#include "philosophers.h"

static void	ft_do_dead(t_philo *philo);
static void	ft_try_eat(t_philo *philo);
static void	ft_do_sleep(t_philo *philo, int curr_time);
static void	ft_do_think(t_philo *philo);

void	*ft_philo_thread(void *philo_void)
{
	t_philo	*philo;
	int		curr_time;

	philo = (t_philo *)philo_void;
	while (philo->state != dead)
	{
		curr_time = ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		if (ft_starved(philo, curr_time))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(philo);
		else if (philo->state == eating)
		{
			ft_do_sleep(philo, curr_time);
			if (ft_eaten_enough(philo))
				break ;
		}
		else if (philo->state == sleeping)
			ft_do_think(philo);
		if (ft_a_philo_died(NULL))
			break ;
	}
	return (philo_void);
}

static void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_philo_state_or_kill(philo);
}

static void	ft_try_eat(t_philo *philo)
{
	if (ft_take_forks(philo, philo->fork_right, philo->fork_left))
	{
		philo->state = eating;
		ft_print_philo_state_or_kill(philo);
		philo->last_eat_ts
			= ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		usleep(philo->timings.time_to_eat * 1000);
		philo->nb_meals++;
	}
}

static void	ft_do_sleep(t_philo *philo, int curr_time)
{
	philo->state = sleeping;
	ft_print_philo_state_or_kill(philo);
	ft_release_forks(philo);
	usleep(ft_max_time_before_dying_in_ms(philo,
			curr_time, philo->timings.time_to_sleep));
}

static void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_philo_state_or_kill(philo);
	usleep(MIN_THINK_TIME);
}
