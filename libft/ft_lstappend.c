#include "libft.h"

void	ft_lstappend(t_list *alst, t_list *new)
{
	if ((new == NULL) || (alst == NULL))
		return ;
	if (alst->next != NULL)
		ft_lstappend(alst->next, new);
	else
		alst->next = new;
}
