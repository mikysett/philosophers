#ifndef FT_INIT_DATA_H
# define FT_INIT_DATA_H

t_data			ft_init_data(int argc, char **argv);

pthread_mutex_t	*ft_init_forks_mutex(void);
pthread_mutex_t	*ft_init_forks(int nb_forks);
void			ft_set_forks_in_philo(t_philo *philo, t_data *data, int i);

#endif
