#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	int		count;
	char	*tmp;
	char	**ret;

	if ((s == NULL) || ((tmp = ft_strdup(s)) == NULL))
		return (NULL);
	count = ft_count_and_delim_words(tmp, c);
	if ((ret = (char **)malloc((count + 1) * sizeof(char *))) == NULL)
		return (NULL);
	if (ft_fill_arr_with_null_term_words(ret, tmp, count) != 1)
		return (NULL);
	*(ret + count) = NULL;
	free(tmp);
	return (ret);
}
