#include "headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	t_list	*p;

	arr = 0;
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear (&arr, del);
			return (arr);
		}
		ft_lstadd_back(&arr, p);
		lst = lst->next;
	}
	return (arr);
}
