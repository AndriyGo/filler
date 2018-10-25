#include "libft.h"

int	ft_fill_arr_with_null_term_words(char **array, char *s, unsigned int count)
{
	while (count > 0)
	{
		if ((ft_strlen(s) == 0))
		{
			s += 1;
			continue ;
		}
		if ((*array = ft_strdup(s)) == NULL)
			return (0);
		s = ft_strchr(s, '\0') + 1;
		array++;
		count--;
	}
	return (1);
}
