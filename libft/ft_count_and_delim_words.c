#include "libft.h"

int	ft_count_and_delim_words(char *s, char delim)
{
	char	*tmp;
	int		count;

	count = 0;
	while ((tmp = ft_strchr(s, delim)) != NULL)
	{
		if ((tmp - s > 0) && (*(tmp - 1) != '\0'))
			count++;
		*tmp = '\0';
		s = ++tmp;
	}
	if (*s != '\0')
		count++;
	return (count);
}
