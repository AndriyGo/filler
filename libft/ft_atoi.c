#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	char	*prcs;
	long	ret;
	int		is_neg;
	int		step;
	char	*tmp;

	prcs = ft_strtrim(str);
	tmp = prcs;
	is_neg = (*prcs == '-');
	if (is_neg || (*prcs == '+'))
		prcs++;
	ret = 0;
	while (*prcs && ft_isdigit(*prcs))
	{
		(is_neg) ? (step = '0' - *prcs) : (step = *prcs - '0');
		if (is_neg && (ret < (-LONG_MAX_LIB - 1 - step) / 10))
			return (0);
		else if (!is_neg && (ret > (LONG_MAX_LIB - step) / 10))
			return (-1);
		else
			ret = ret * 10 + step;
		prcs++;
	}
	free(tmp);
	return ((int)ret);
}