#ifndef FT_SINGLE_PHILO_H
# define FT_SINGLE_PHILO_H

void	*ft_single_philo(void *philo_void);

bool	ft_eaten_enough(t_philo *philo);
bool	ft_starved(t_philo *philo, int curr_time);
int		ft_max_time_before_dying_in_ms(t_philo *philo,
			int curr_time, int time_to_wait);

#endif
