#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	if ((ret = ft_strdup(s)) == NULL)
		return (NULL);
	tmp = ret;
	while (*tmp)
	{
		*tmp = f(*tmp);
		tmp++;
	}
	return (ret);
}
