#ifndef FT_TIME_UTIL_H
# define FT_TIME_UTIL_H

t_timeval	ft_get_tv(void);
int			ft_delta_tv_in_ms(t_timeval old_tv, t_timeval new_tv);
#endif
