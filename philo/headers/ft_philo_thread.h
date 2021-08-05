#ifndef FT_PHILO_THREAD_H
# define FT_PHILO_THREAD_H

void	*ft_philo_thread(void *philo_void);

bool	ft_eaten_enough(t_philo *philo);
bool	ft_starved(t_philo *philo, int curr_time);
int		ft_max_time_before_dying_in_ms(t_philo *philo,
			int curr_time, int time_to_wait);
bool	ft_a_philo_died(bool set_death, pthread_mutex_t *a_philo_died_mutex);

#endif
