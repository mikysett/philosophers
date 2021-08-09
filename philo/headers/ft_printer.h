#ifndef FT_PRINTER_H
# define FT_PRINTER_H

pthread_mutex_t	*ft_init_printer_mutex(void);
void			ft_print_state_or_kill(t_philo *philo);

#endif
