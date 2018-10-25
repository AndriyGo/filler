#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;

	if ((ret = (char *)ft_memalloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	return (ret);
}
