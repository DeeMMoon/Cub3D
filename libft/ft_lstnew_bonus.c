#include "headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *) malloc(sizeof(*p));
	if (!p)
		return (0);
	p -> content = content;
	p -> next = 0;
	return (p);
}
