#include "philosophers.h"

static void	ft_kill_all_children(t_data *data);

void	ft_catch_results(t_data *data)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus)
			&& WEXITSTATUS(wstatus) == EXIT_FAILURE)
			ft_kill_all_children(data);
		i++;
	}
}

static void	ft_kill_all_children(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		kill(data->philo_pids[i], SIGKILL);
		i++;
	}
}
