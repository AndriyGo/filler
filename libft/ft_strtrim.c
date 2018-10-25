#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			length;
	char			*tmp;

	if (s == NULL)
		return (NULL);
	start = 0;
	tmp = (char *)s;
	while (ft_iswhitespace(*tmp))
	{
		tmp++;
		start++;
	}
	length = ft_strlen(s);
	if (length == start)
		return (ft_strdup(""));
	tmp = (char *)s + length - 1;
	length -= start;
	while (ft_iswhitespace(*tmp))
	{
		tmp--;
		length--;
	}
	return (ft_strsub(s, start, length));
}
