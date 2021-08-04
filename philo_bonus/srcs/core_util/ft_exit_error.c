#include "philosophers.h"

static void	ft_print_err(t_exit_code exit_code);

void	ft_exit_error(t_data *data, t_exit_code exit_code)
{
	if (exit_code != SKIP_PRINTING)
		ft_print_err(exit_code);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

static void	ft_print_err(t_exit_code exit_code)
{
	if (exit_code == WRONG_ARGUMENT_NB)
		printf("Error: Wrong number of arguments\n");
	else if (exit_code == WRONG_ARGUMENT_TYPE)
		printf("Error: Arguments must be positive integers\n");
	else if (exit_code == MEMORY_FAIL)
		printf("Error: Can't allocate memory\n");
	else if (exit_code == TIMEVAL_ERROR)
		printf("Error: Can't get time value\n");
	else if (exit_code == FORK_FAIL)
		printf("Error: Can't fork the process\n");
	else if (exit_code == KILL_FAIL)
		printf("Error: Can't kill the process\n");
	else if (exit_code == SEMAPHORE_FAIL)
		printf("Error: Can't initialize forks with semaphore\n");
	// else if (exit_code == MUTEX_DESTROY_FAIL)
	// 	printf("Error: Can't destroy forks with mutex\n");
	else if (exit_code == THREAD_CREATE_FAIL)
		printf("Error: Can't create the thread\n");
	else if (exit_code == THREAD_DETACH_FAIL)
		printf("Error: Can't detach the thread\n");
	// else if (exit_code == THREAD_JOIN_FAIL)
	// 	printf("Error: Can't join the threads\n");
	else if (exit_code == SEM_LOCK_FAIL)
		printf("Error: Can't lock the semaphore\n");
	else if (exit_code == SEM_UNLOCK_FAIL)
		printf("Error: Can't unlock the semaphore\n");
	else
		printf("Error: Unknown error\n");
}
