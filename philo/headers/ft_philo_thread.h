#ifndef FT_PHILO_THREAD_H
# define FT_PHILO_THREAD_H

void	*ft_philo_thread(void *philo_void);

bool	ft_eaten_enough(t_philo *philo);
bool	ft_starved(t_philo *philo);
int		ft_max_time_before_dying_in_us(t_philo *philo, int time_to_wait_in_us);

#endif
