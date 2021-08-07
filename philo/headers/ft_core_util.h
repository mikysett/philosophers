#ifndef FT_CORE_UTIL_H
# define FT_CORE_UTIL_H

int			ft_save_number(char *arr_nb);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
void		ft_exit_error(t_data *data, t_exit_code exit_code);
int			previous(int i, int size);

void		ft_free_data(t_data *data);
bool		*ft_init_is_fork_busy(int nb_philo);
void		*ft_malloc_or_exit(int size);

void		ft_init_mutex(pthread_mutex_t *mutex);
void		ft_lock_mutex(pthread_mutex_t *mutex);
void		ft_unlock_mutex(pthread_mutex_t *mutex);
void		ft_destroy_mutex(pthread_mutex_t *mutex);

#endif
