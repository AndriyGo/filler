#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		if (*((unsigned char *)dst) == (unsigned char)c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
