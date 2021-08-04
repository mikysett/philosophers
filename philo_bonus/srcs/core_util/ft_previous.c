#include "philosophers.h"

int	previous(int i, int size)
{
	if (i == 0)
		return (size - 1);
	return (i - 1);
}
