#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s++;
	}
	if (*((char *)s) == (char)c)
			return ((char *)s);
	return (NULL);
}
