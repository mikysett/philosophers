#include "philosophers.h"

static int	ft_set_nb_times_to_eat(int argc, char **argv);

t_data	ft_init_data(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		ft_exit_error(NULL, WRONG_ARGUMENT_NB);
	data.nb_philo = ft_save_number(argv[1]);
	data.time_to_die = ft_save_number(argv[2]);
	data.time_to_eat = ft_save_number(argv[3]);
	data.time_to_sleep = ft_save_number(argv[4]);
	data.nb_times_to_eat = ft_set_nb_times_to_eat(argc, argv);
	// data.last_ts = 0;
	// ft_init_philo(&data);
	// ft_init_forks(&data);
	// ft_init_philo_output(&data);
	return (data);
}

static int	ft_set_nb_times_to_eat(int argc, char **argv)
{
	if (argc == 6)
		return (ft_save_number(argv[5]));
	else
		return (EAT_FOREVER);
}

// void	ft_init_philo(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
// 	if (!data->philo)
// 		ft_exit_error(NULL, MEMORY_FAIL);
// 	while (i < data->nb_philo)
// 	{
// 		data->philo[i].id = i + 1;
// 		data->philo[i].state = thinking;
// 		data->philo[i].forks_in_hand = 0;
// 		data->philo[i].last_eat_ts = 0;
// 		data->philo[i].last_sleep_ts = -1;
// 		i++;
// 	}
// }

// void	ft_init_forks(t_data *data)
// {
// 	data->busy_forks = ft_calloc(data->nb_philo, sizeof(bool));
// 	if (!data->busy_forks)
// 		ft_exit_error(NULL, MEMORY_FAIL);
// }
