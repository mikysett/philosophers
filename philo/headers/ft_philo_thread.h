#ifndef FT_PHILO_THREAD_H
# define FT_PHILO_THREAD_H

void	*ft_philo_thread(void *philo_void);

bool	ft_eaten_enough(t_philo *philo);
bool	ft_starved(t_philo *philo, int curr_time);
int		ft_max_time_before_dying_in_ms(t_philo *philo,
			int curr_time, int time_to_wait);

#endif
