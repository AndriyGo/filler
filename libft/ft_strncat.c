#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *ret;

	ret = s1;
	while (*s1) 
		s1++;
	while (*s2 && (n-- > 0))
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (ret);
}
