#include "philosophers.h"

static int	ft_set_nb_times_to_eat(int argc, char **argv);

t_data	ft_init_data(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		ft_exit_error(NULL, WRONG_ARGUMENT_NB);
	data.nb_philo = ft_save_number(argv[1]);
	data.timings = ft_init_timings(argc, argv);
	data.philo = ft_init_philo(data.timings, data.nb_philo);
	// data.last_ts = 0;
	// ft_init_forks(&data);
	// ft_init_philo_output(&data);
	return (data);
}

static t_timings	ft_init_timings(int argc, char **argv)
{
	t_timings	timings;

	timings.time_to_die = ft_save_number(argv[2]);
	timings.time_to_eat = ft_save_number(argv[3]);
	timings.time_to_sleep = ft_save_number(argv[4]);
	timings.nb_times_to_eat = ft_set_nb_times_to_eat(argc, argv);
	return (timings);
}

static int	ft_set_nb_times_to_eat(int argc, char **argv)
{
	if (argc == 6)
		return (ft_save_number(argv[5]));
	else
		return (EAT_FOREVER);
}

static t_philo	*ft_init_philo(t_timings timings, int nb_philo)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		ft_exit_error(NULL, MEMORY_FAIL);
	while (i < nb_philo)
	{
		philo[i].timings = timings;
		philo[i].id = i + 1;
		philo[i].state = thinking;
		philo[i].forks_in_hand = 0;
		philo[i].last_eat_ts = 0;
		philo[i].last_sleep_ts = -1;
		philo[i].nb_meals = 0;
		i++;
	}
	return (philo);
}

// void	ft_init_forks(t_data *data)
// {
// 	data->busy_forks = ft_calloc(data->nb_philo, sizeof(bool));
// 	if (!data->busy_forks)
// 		ft_exit_error(NULL, MEMORY_FAIL);
// }
