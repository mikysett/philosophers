#ifndef FT_FORKS_UTIL_H
# define FT_FORKS_UTIL_H

void	*ft_take_forks(void *philo_void);
void	ft_release_forks(t_philo *philo);
int		ft_get_forks_in_hand(t_philo *philo);
void	ft_set_forks_in_hand(t_philo *philo, int new_forks_in_hand);

#endif
