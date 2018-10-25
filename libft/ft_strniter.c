#include <string.h>

void	ft_strniter(char *s, void (*f)(char *), size_t n)
{
	if ((s == NULL) || (f == NULL))
		return ;
	while (*s && (n-- > 0))
		f(s++);
}
