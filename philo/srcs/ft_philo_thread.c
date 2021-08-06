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
	while (philo->state != dead
		&& !(philo->state == sleeping && ft_eaten_enough(philo)))
	{
		curr_time = ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		if (ft_starved(philo, curr_time))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(philo);
		else if (philo->state == eating)
			ft_do_sleep(philo, curr_time);
		else if (philo->state == sleeping)
			ft_do_think(philo);
		if (ft_a_philo_died(NULL, philo->a_philo_died_mutex))
			break ;
	}
	return (philo_void);
}

static void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_philo_state(philo);
}

static void	ft_try_eat(t_philo *philo)
{
	if (ft_take_forks(philo))
	{
		philo->state = eating;
		ft_print_philo_state(philo);
		philo->last_eat_ts
			= ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		usleep(philo->timings.time_to_eat * 1000);
		philo->nb_meals++;
	}
}

static void	ft_do_sleep(t_philo *philo, int curr_time)
{
	philo->state = sleeping;
	ft_print_philo_state(philo);
	// ft_release_forks(philo);
	ft_release_fork(philo->fork_right, philo->is_fork_right_busy);
	ft_release_fork(philo->fork_left, philo->is_fork_left_busy);
	usleep(ft_max_time_before_dying_in_ms(philo,
			curr_time, philo->timings.time_to_sleep));
}

static void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_philo_state(philo);
	usleep(MIN_THINK_TIME);
}
