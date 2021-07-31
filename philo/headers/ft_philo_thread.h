#ifndef FT_PHILO_THREAD_H
# define FT_PHILO_THREAD_H

void	*ft_philo_thread(void *philo_void);
bool	ft_starved(t_philo *philo, int curr_time);
bool	ft_eaten_enough(t_philo *philo);
void	ft_do_dead(t_philo *philo);
void	ft_try_eat(t_philo *philo, int curr_time);
void	ft_do_sleep(t_philo *philo);
void	ft_do_think(t_philo *philo);

#endif
