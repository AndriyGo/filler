#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ((alst == NULL) || (*alst == NULL))
		return ;
	if ((*alst)->content != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
	}
	(*alst)->next = NULL;
	free(*alst);
	*alst = NULL;
}
