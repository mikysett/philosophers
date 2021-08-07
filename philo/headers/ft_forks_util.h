#ifndef FT_FORKS_UTIL_H
# define FT_FORKS_UTIL_H

bool	ft_take_forks(t_philo *philo);
void	ft_release_fork(pthread_mutex_t *fork, bool *is_fork_busy);

#endif
