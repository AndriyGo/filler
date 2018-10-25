#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL)
		return (s2 == NULL);
	if (s2 == NULL)
		return (s1 == NULL);
	return (ft_strcmp(s1, s2) == 0);
}