#include "headers/libft.h"

size_t	ft_strlen(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *) s;
	i = 0;
	while (p[i])
	{
		i++;
	}
	return (i);
}
