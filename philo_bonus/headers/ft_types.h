#ifndef FT_TYPES_H
# define FT_TYPES_H

/* Eat forever must be a negative number */

# define EAT_FOREVER		-1
# define ONE_SEC_IN_USEC	1000000
# define MIN_THINK_TIME		500

typedef enum e_exit_code
{
	SKIP_PRINTING,
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE,
	MEMORY_FAIL,
	TIMEVAL_ERROR,
	FORK_FAIL,
	KILL_FAIL,
	// MUTEX_FAIL,
	// MUTEX_DESTROY_FAIL,
	SEMAPHORE_FAIL,
	THREAD_CREATE_FAIL,
	THREAD_DETACH_FAIL,
	// THREAD_JOIN_FAIL,
	SEM_LOCK_FAIL,
	SEM_UNLOCK_FAIL
}			t_exit_code;

typedef struct timeval	t_timeval;

typedef struct s_timings
{
	t_timeval	start_time;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
}			t_timings;

/* Philo states must be in this order so they match the  string array in */
/* ft_print_philo_state() */

typedef enum e_philo_state
{
	fork_taken,
	eating,
	sleeping,
	thinking,
	dead
}			t_philo_state;	

typedef struct s_philo
{
	int				id;
	t_philo_state	state;
	int				nb_meals;
	int				last_eat_ts;
	t_timings		timings;
	pthread_mutex_t	*printer_mutex;
	sem_t			*forks;
	int				forks_in_hand;
}			t_philo;

typedef struct s_data
{
	int			nb_philo;
	t_philo		*philo;
	sem_t		*forks;
	pid_t		*philo_pids;
}			t_data;

#endif
