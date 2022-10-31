#include "headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			result = (unsigned char *)(s + i);
			return (result);
		}
		i++;
	}
	return (0);
}
