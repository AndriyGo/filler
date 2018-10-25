#include <string.h>

void	ft_strniteri(char *s, void (*f)(unsigned int, char *), size_t n)
{
	unsigned int	i;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return ;
	while (*s && (n-- > 0))
		f(i++, s++);
}
