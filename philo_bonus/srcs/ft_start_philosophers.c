#include "philosophers.h"

void	ft_start_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo_pids[i] = fork();
		if (data->philo_pids[i] == -1)
			ft_exit_error(data, FORK_FAIL);
		else if (data->philo_pids[i] == 0)
		{
			ft_single_philo((void *)&data->philo[i]);
			ft_free_data(data);
			if (data->philo[i].state == dead)
				exit(EXIT_FAILURE);
			else
				exit(EXIT_SUCCESS);
		}
		i++;
	}
}