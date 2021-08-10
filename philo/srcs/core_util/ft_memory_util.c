#include "philosophers.h"

static void	ft_free_forks(t_data *data);

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_forks(data);
		ft_destroy_mutex(data->printer_mutex);
		free(data->printer_mutex);
		free(data->is_fork_busy);
		free(data->philo_threads);
		free(data->philo);
	}
}

static void	ft_free_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		ft_destroy_mutex(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

bool	*ft_init_is_fork_busy(int nb_philo)
{
	int		i;
	bool	*is_fork_busy;

	i = 0;
	is_fork_busy = ft_malloc_or_exit(sizeof(bool) * nb_philo);
	if (nb_philo == 1)
		is_fork_busy[0] = true;
	else
	{
		while (i < nb_philo)
		{
			is_fork_busy[i] = false;
			i++;
		}
	}
	return (is_fork_busy);
}

void	*ft_malloc_or_exit(int size)
{
	void	*malloc_result;

	malloc_result = malloc(size);
	if (!malloc_result)
		ft_exit_error(NULL, MEMORY_FAIL);
	return (malloc_result);
}
