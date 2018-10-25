#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	s = s + len;
	while (len-- > 0)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s--;
	}
	if (*((char *)s) == (char)c)
			return ((char *)s);
	return (NULL);
}