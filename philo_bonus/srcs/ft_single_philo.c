#include "philosophers.h"

static void	ft_do_dead(t_philo *philo);
static void	ft_try_eat(pthread_t *take_forks, t_philo *philo);
static void	ft_do_sleep(t_philo *philo, int curr_time);
static void	ft_do_think(t_philo *philo);

void	*ft_single_philo(void *philo_void)
{
	t_philo		*philo;
	int			curr_time;
	pthread_t	*take_forks;

	philo = (t_philo *)philo_void;
	take_forks = ft_malloc_or_exit(sizeof(pthread_t));
	philo->read_forks_in_hand = ft_init_read_forks_in_hand(philo);
	while (philo->state != dead
		&& !(philo->state == sleeping && ft_eaten_enough(philo)))
	{
		curr_time = ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		if (ft_starved(philo, curr_time))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(take_forks, philo);
		else if (philo->state == eating)
			ft_do_sleep(philo, curr_time);
		else if (philo->state == sleeping)
			ft_do_think(philo);
	}
	free(take_forks);
	return (philo_void);
}

static void	ft_try_eat(pthread_t *take_forks, t_philo *philo)
{
	static bool		trying_to_take_forks = false;

	if (trying_to_take_forks == false)
	{
		if (pthread_create(take_forks, NULL, ft_take_forks, (void *)philo) != 0)
			ft_exit_error(NULL, THREAD_CREATE_FAIL);
		if (pthread_detach(*take_forks))
			ft_exit_error(NULL, THREAD_DETACH_FAIL);
		trying_to_take_forks = true;
	}
	else if (ft_get_forks_in_hand(philo) >= 2)
	{
		philo->state = fork_taken;
		ft_print_philo_state(philo);
		ft_print_philo_state(philo);
		ft_do_eat(philo);
		trying_to_take_forks = false;
	}
}

static void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_philo_state(philo);
}

static void	ft_do_sleep(t_philo *philo, int curr_time)
{
	philo->state = sleeping;
	ft_print_philo_state(philo);
	ft_release_forks(philo);
	usleep(ft_max_time_before_dying_in_ms(philo,
			curr_time, philo->timings.time_to_sleep));
}

static void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_philo_state(philo);
	usleep(MIN_THINK_TIME);
}
