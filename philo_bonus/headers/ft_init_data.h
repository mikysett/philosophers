#ifndef FT_INIT_DATA_H
# define FT_INIT_DATA_H

t_data	ft_init_data(int argc, char **argv);

sem_t	*ft_init_forks(int nb_forks);
sem_t	*ft_init_printer(void);

#endif
