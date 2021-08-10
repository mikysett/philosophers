#include "philosophers.h"

static void	ft_do_dead(t_philo *philo);
static void	ft_try_eat(t_philo *philo);
static void	ft_do_sleep(t_philo *philo);
static void	ft_do_think(t_philo *philo);

void	*ft_philo_thread(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (philo->state != dead
		&& !(philo->state == sleeping && ft_eaten_enough(philo)))
	{
		if (ft_starved(philo))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(philo);
		else if (philo->state == eating)
			ft_do_sleep(philo);
		else if (philo->state == sleeping)
			ft_do_think(philo);
	}
	return (philo_void);
}

static void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_state_or_kill(philo);
}

static void	ft_try_eat(t_philo *philo)
{
	if (ft_take_forks(philo))
	{
		philo->state = eating;
		ft_print_state_or_kill(philo);
		philo->last_eat_tv = ft_get_tv();
		ft_sleep(philo->last_eat_tv, philo->timings.time_to_eat_in_us);
		philo->nb_meals++;
	}
}

static void	ft_do_sleep(t_philo *philo)
{
	philo->state = sleeping;
	ft_print_state_or_kill(philo);
	ft_release_fork(philo->fork_right, philo->is_fork_right_busy);
	ft_release_fork(philo->fork_left, philo->is_fork_left_busy);
	ft_sleep(ft_get_tv(),
		ft_max_time_before_dying_in_us(philo,
			philo->timings.time_to_sleep_in_us));
}

static void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_state_or_kill(philo);
	usleep(MIN_THINK_TIME);
}
