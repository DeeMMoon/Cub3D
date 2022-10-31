#include "headers/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*call;

	call = malloc(size * count);
	if (!call)
		return (0);
	ft_bzero (call, count * size);
	return (call);
}
