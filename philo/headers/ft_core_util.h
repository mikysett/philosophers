#ifndef FT_CORE_UTIL_H
# define FT_CORE_UTIL_H

int			ft_save_number(char *arr_nb);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
void		ft_exit_error(t_data *data, t_exit_code exit_code);
int			previous(int i, int size);

void		ft_free_data(t_data *data);
pthread_t	*ft_init_philo_threads(int nb_philo);
bool		*ft_init_is_fork_busy(int nb_philo);

#endif
