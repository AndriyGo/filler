#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if ((ret = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}