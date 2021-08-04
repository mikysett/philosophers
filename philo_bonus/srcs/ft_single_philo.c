#include "philosophers.h"

static void	ft_do_dead(t_philo *philo);
static void	ft_do_eat(t_philo *philo);
static void	ft_do_sleep(t_philo *philo, int curr_time);
static void	ft_do_think(t_philo *philo);
static void ft_start_take_forks(pthread_t *take_forks, t_philo *philo);

void	*ft_single_philo(void *philo_void)
{
	t_philo		*philo;
	bool	trying_to_take_forks = false;
	int		curr_time;

	pthread_t	*take_forks = malloc(sizeof(pthread_t));

	philo = (t_philo *)philo_void;
	while (philo->state != dead)
	{
		printf("-----------> p%d forks in hand: %d\n", philo->id, philo->forks_in_hand);
		curr_time = ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
		if (ft_starved(philo, curr_time))
			ft_do_dead(philo);
		else if (philo->state == thinking)
		{
			if (trying_to_take_forks)
			{
				// if (philo->forks_in_hand == 1)
				// {
				// 	if (sem_post(philo->forks) != 0)
				// 		ft_exit_error(NULL, SEM_UNLOCK_FAIL);
				// 	philo->forks_in_hand--;
				// 	printf("releasing a fork to avoid deadlocks\n");
				// }
			}
			else
			{
				ft_start_take_forks(take_forks, philo);
				trying_to_take_forks = true;
			}
			if (philo->forks_in_hand == 2)
			{
				ft_do_eat(philo);
				trying_to_take_forks = false;
			}
		}
		else if (philo->state == eating)
		{
			ft_do_sleep(philo, curr_time);
			if (ft_eaten_enough(philo))
				break ;
		}
		else if (philo->state == sleeping)
			ft_do_think(philo);
		// if (ft_a_philo_died(NULL))
		// 	break ;
	}
	free(take_forks);
	return (philo_void);
}

static void	ft_start_take_forks(pthread_t *take_forks, t_philo *philo)
{
	// printf("start take forks\n");
	if (!take_forks)
		ft_exit_error(NULL, MEMORY_FAIL);
	if (pthread_create(take_forks, NULL, ft_take_forks, (void *)philo) != 0)
		ft_exit_error(NULL, THREAD_CREATE_FAIL);
	if (pthread_join(*take_forks, NULL))
		ft_exit_error(NULL, THREAD_DETACH_FAIL);
}

static void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_philo_state(philo);
}

static void	ft_do_eat(t_philo *philo)
{
	philo->state = eating;
	ft_print_philo_state(philo);
	philo->last_eat_ts
		= ft_delta_tv_in_ms(philo->timings.start_time, ft_get_tv());
	usleep(philo->timings.time_to_eat * 1000);
	philo->nb_meals++;
}

static void	ft_do_sleep(t_philo *philo, int curr_time)
{
	philo->state = sleeping;
	ft_print_philo_state(philo);
	printf("releasing some forks\n");
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
