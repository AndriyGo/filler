#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;

	ret = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ret == (unsigned char)c)
			return (ret);
		ret++;
	}
	return (NULL);
}
