#include <stdlib.h>
#include <string.h>

char	*ft_itoa(int n)
{
	int		size;
	int		copy;
	int		is_neg;
	char	*ret;

	copy = n;
	is_neg = (n < 0);
	size = is_neg + (n == 0);
	while (copy != 0)
	{
		copy /= 10;
		size++;
	}
	if ((ret = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ret[size] = '\0';
	while (size > is_neg)
	{
		ret[size - 1] = ((is_neg) ? (-1 * (n % 10)) : (n % 10)) + '0';
		n /= 10;
		size--;
	}
	if (size == 1)
		ret[0] = '-';
	return (ret);
}
