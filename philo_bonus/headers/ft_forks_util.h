#ifndef FT_FORKS_UTIL_H
# define FT_FORKS_UTIL_H

bool	ft_take_forks(t_philo *philo, pthread_mutex_t *fork_right,
			pthread_mutex_t *fork_left);
void	ft_release_forks(t_philo *philo);

#endif
