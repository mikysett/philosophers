#include "philosophers.h"

void	ft_start_philosophers(t_data *data)
{
	int	i;
	int	sgl_philo_status;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo_pids[i] = fork();
		if (data->philo_pids[i] == -1)
			ft_exit_error(data, FORK_FAIL);
		else if (data->philo_pids[i] == 0)
		{
			ft_single_philo((void *)&data->philo[i]);
			if (data->philo[i].state == dead)
				sgl_philo_status = EXIT_FAILURE;
			else
				sgl_philo_status = EXIT_SUCCESS;
			ft_free_data(data);
			exit(sgl_philo_status);
		}
		i++;
	}
}
