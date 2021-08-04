#include "philosophers.h"

void	ft_catch_results(t_data *data)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus)
			&& WIFEXITSTATUS(wstatus) == EXIT_FAILURE)
		{
			if (kill(-1, SIGKILL) == -1)
				ft_exit_error(data, KILL_FAIL);
		}
		i++;
	}
}
