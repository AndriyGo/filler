#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*ret;

	if (lst == NULL)
		return (NULL);
	ret = ft_lstnew(lst->content, lst->content_size);
	return (ret);
}
