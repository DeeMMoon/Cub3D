#include "headers/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	char	*p;

	p = (char *) src;
	j = 0;
	while (p[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	i = 0;
	size--;
	while (p[i] != '\0' && i < (size))
	{
		dest[i] = p[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
