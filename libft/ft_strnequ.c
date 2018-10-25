#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL)
		return (s2 == NULL);
	if (s2 == NULL)
		return (s1 == NULL);
	return (ft_strncmp(s1, s2, n) == 0);
}
