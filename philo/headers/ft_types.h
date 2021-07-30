#ifndef FT_TYPES_H
# define FT_TYPES_H

#define EAT_FOREVER	-1

typedef enum e_exit_code
{
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE,
	MEMORY_FAIL
}			t_exit_code;

typedef struct s_timings
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
}			t_timings;

typedef enum e_philo_state
{
	eating,
	sleeping,
	thinking,
	dead,
	fork_taken
}			t_philo_state;	

typedef struct s_philo
{
	t_timings		timings;
	int				id;
	t_philo_state	state;
	int				forks_in_hand;
	int				last_eat_ts;
	int				last_sleep_ts;
	int				nb_meals;
}			t_philo;

typedef struct e_data
{
	int			nb_philo;
	t_timings	timings;
	t_philo		*philo;
}			t_data;

#endif
