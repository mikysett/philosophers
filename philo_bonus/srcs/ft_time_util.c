#include "philosophers.h"

t_timeval	ft_get_tv(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_exit_error(NULL, TIMEVAL_ERROR);
	return (time);
}

int	ft_delta_tv_in_ms(t_timeval old_tv, t_timeval new_tv)
{
	long int	delta_tv_sec;
	long int	delta_tv_usec;

	delta_tv_sec = new_tv.tv_sec - old_tv.tv_sec;
	delta_tv_usec = new_tv.tv_usec - old_tv.tv_usec;
	if (delta_tv_usec < 0)
	{
		delta_tv_sec--;
		delta_tv_usec += ONE_SEC_IN_USEC;
	}
	return ((delta_tv_sec * 1000) + (delta_tv_usec / 1000));
}
