#ifndef FT_TYPES_H
# define FT_TYPES_H

/* Eat forever must be a negative number */

# define EAT_FOREVER		-1
# define ONE_SEC_IN_USEC	1000000

typedef enum e_exit_code
{
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE,
	MEMORY_FAIL,
	TIMEVAL_ERROR
}			t_exit_code;

typedef struct timeval t_timeval;

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
	t_timings		timings;
	int				id;
	t_philo_state	state;
	int				forks_in_hand;
	int				last_eat_ts;
	int				nb_meals;
}			t_philo;

typedef struct e_data
{
	int			nb_philo;
	t_philo		*philo;
}			t_data;

#endif
