#include "headers/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *) str;
	while (i < len)
	{
		s[i] = c;
		i ++;
	}
	return (s);
}
