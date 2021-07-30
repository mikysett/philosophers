#ifndef FT_TYPES_H
# define FT_TYPES_H

#define EAT_FOREVER	-1

typedef enum e_exit_code
{
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE
}			t_exit_code;

typedef struct e_data
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
}			t_data;

#endif
