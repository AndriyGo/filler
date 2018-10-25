#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*tmp;
	unsigned int	idx;

	if (s == NULL)
		return (NULL);
	if ((ret = ft_strdup(s)) == NULL)
		return (NULL);
	tmp = ret;
	idx = 0;
	while (*tmp)
	{
		*tmp = f(idx++, *tmp);
		tmp++;
	}
	return (ret);
}