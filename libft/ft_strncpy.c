#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ret;

	ret = dst;
	while (*src && (len > 0))
	{
		*(dst++) = *(src++);
		--len;
	}
	while (len > 0)
	{
		*(dst++) = '\0';
		--len;
	}
	return (ret);
}
