#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	big_len = ft_strlen(big);
	while ((big_len-- >= little_len) && (len-- >= little_len))
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
