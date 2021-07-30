#include "philosophers.h"

static bool	ft_is_number(char *nb);
static bool	ft_is_int(char *nb);
static void	ft_delete_starting_zeros(char *nb);
static int	ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_save_number(char *arr_nb)
{
	int	nb;

	if (!ft_is_number(arr_nb) || !ft_is_int(arr_nb))
		ft_exit_error(NULL, WRONG_ARGUMENT_TYPE);
	nb = ft_atoi(arr_nb);
	if (nb <= 0)
		ft_exit_error(NULL, WRONG_ARGUMENT_TYPE);
	return (nb);
}

static bool	ft_is_number(char *nb)
{
	if (*nb == '-')
		nb++;
	if (!*nb)
		return (false);
	while (*nb)
	{
		if (*nb < '0' || *nb > '9')
			return (false);
		nb++;
	}
	return (true);
}

static bool	ft_is_int(char *nb)
{
	size_t	nb_size;
	char	*nb_char;

	ft_delete_starting_zeros(nb);
	nb_size = ft_strlen(nb);
	nb_char = ft_itoa(ft_atoi(nb));
	if (nb_size != ft_strlen(nb_char)
		|| ft_strncmp(nb, nb_char, nb_size))
	{
		free(nb_char);
		return (false);
	}
	free(nb_char);
	return (true);
}

static void	ft_delete_starting_zeros(char *nb)
{
	int	i;
	int	nb_len;

	i = 0;
	nb_len = strlen(nb);
	if (*nb == '0' && nb_len != 1)
	{
		while (i < nb_len)
		{
			nb[i] = nb[i + 1];
			i++;	
		}
		ft_delete_starting_zeros(nb);
	}
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n > 0 && *(s1) == *(s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*(s1) - (unsigned char)*(s2));
}
