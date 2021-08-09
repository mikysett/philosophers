#ifndef FT_TIME_UTIL_H
# define FT_TIME_UTIL_H

t_timeval	ft_get_tv(void);
long long	ft_delta_tv_in_us(t_timeval old_tv, t_timeval new_tv);
void		ft_sleep(t_timeval start_time, int time_to_sleep_in_us);

#endif
