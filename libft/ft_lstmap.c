#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*ret;

	if ((lst == NULL) || ((ret = ft_lstcpy(lst)) == NULL))
		return (NULL);
	ret = f(ret);
	ret->next = ft_lstmap(lst->next, f);
	return (ret);
}
