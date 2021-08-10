#include "philosophers.h"

t_timeval	ft_get_tv(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_exit_error(NULL, TIMEVAL_ERROR);
	return (time);
}

long long	ft_delta_tv_in_us(t_timeval old_tv, t_timeval new_tv)
{
	return (((new_tv.tv_sec - old_tv.tv_sec) * ONE_SEC_IN_USEC)
		+ new_tv.tv_usec - old_tv.tv_usec);
}

void	ft_sleep(t_timeval start_time, int time_to_sleep_in_us)
{
	usleep(time_to_sleep_in_us - time_to_sleep_in_us / 10);
	while (ft_delta_tv_in_us(start_time, ft_get_tv())
		<= time_to_sleep_in_us)
		continue ;
}
