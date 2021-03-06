#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*link;

	if (!lst)
		return (NULL);
	link = f(lst);
	new = link;
	while (lst->next)
	{
		lst = lst->next;
		if (!(link->next = f(lst)))
		{
			free(link->next);
			return (NULL);
		}
		link = link->next;
	}
	return (new);
}
