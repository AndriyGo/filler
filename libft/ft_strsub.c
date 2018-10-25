#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	if ((ret = ft_memalloc(len + 1)) == NULL)
		return (NULL);
	tmp = ret;
	while (len-- > 0)
		*(tmp++) = *(s + start++);
	*tmp = '\0';
	return (ret);
}