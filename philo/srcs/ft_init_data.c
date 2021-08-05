#include "philosophers.h"

static t_timings		ft_init_timings(int argc, char **argv);
static int				ft_set_nb_times_to_eat(int argc, char **argv);
static t_philo			*ft_init_philo(t_data *data, t_timings timings);

t_data	ft_init_data(int argc, char **argv)
{
	t_data		data;
	t_timings	timings;

	if (argc < 5 || argc > 6)
		ft_exit_error(NULL, WRONG_ARGUMENT_NB);
	data.nb_philo = ft_save_number(argv[1]);
	data.forks = ft_init_forks(data.nb_philo);
	data.busy_forks_mutex = ft_init_busy_forks_mutex();
	data.a_philo_died_mutex = ft_init_a_philo_died_mutex();
	data.is_fork_busy = ft_init_is_fork_busy(data.nb_philo);
	ft_init_printer_mutex(&data);
	timings = ft_init_timings(argc, argv);
	data.philo = ft_init_philo(&data, timings);
	data.philo_threads = ft_init_philo_threads(data.nb_philo);
	return (data);
}

static t_timings	ft_init_timings(int argc, char **argv)
{
	t_timings	timings;

	timings.start_time = ft_get_tv();
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

static t_philo	*ft_init_philo(t_data *data, t_timings timings)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		ft_exit_error(NULL, MEMORY_FAIL);
	while (i < data->nb_philo)
	{
		philo[i].timings = timings;
		philo[i].id = i + 1;
		philo[i].state = thinking;
		philo[i].last_eat_ts = 0;
		philo[i].nb_meals = 0;
		ft_set_forks_in_philo(philo, data, i);
		philo[i].printer_mutex = data->printer_mutex;
		philo[i].busy_forks_mutex = data->busy_forks_mutex;
		philo[i].a_philo_died_mutex = data->a_philo_died_mutex;
		i++;
	}
	return (philo);
}
