#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/signal.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

# include <pthread.h>

# include "ft_types.h"
# include "ft_core_util.h"
# include "ft_time_util.h"
# include "ft_forks_util.h"
# include "ft_init_data.h"
# include "ft_printer.h"
# include "ft_single_philo.h"
# include "ft_start_philosophers.h"
# include "ft_catch_results.h"

#endif
