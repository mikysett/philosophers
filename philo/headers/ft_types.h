#ifndef FT_TYPES_H
# define FT_TYPES_H

/* Eat forever must be a negative number */

# define EAT_FOREVER		-1
# define ONE_SEC_IN_USEC	1000000
# define MIN_THINK_TIME		100

typedef enum e_exit_code
{
	SKIP_PRINTING,
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE,
	MEMORY_FAIL,
	TIMEVAL_ERROR,
	MUTEX_FAIL,
	MUTEX_DESTROY_FAIL,
	THREAD_CREATE_FAIL,
	THREAD_JOIN_FAIL,
	MUTEX_LOCK_FAIL,
	MUTEX_UNLOCK_FAIL
}			t_exit_code;

typedef struct timeval	t_timeval;

typedef struct s_timings
{
	t_timeval	start_time;
	long		time_to_die_us;
	long		time_to_eat_in_us;
	long		time_to_sleep_in_us;
	long		min_time_to_think_in_us;
	int			nb_times_to_eat;
}			t_timings;

/* Philo states must be in this order so they match the  string array in */
/* ft_print_state_or_kill() */

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
	t_timeval		last_eat_tv;
	t_timings		timings;

	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	bool			*is_fork_right_busy;
	bool			*is_fork_left_busy;

	pthread_mutex_t	*printer_mutex;
}			t_philo;

typedef struct s_data
{
	int				nb_philo;
	t_philo			*philo;
	bool			*is_fork_busy;
	pthread_t		*philo_threads;

	pthread_mutex_t	*forks;
	pthread_mutex_t	*printer_mutex;
}			t_data;

#endif
