#include "headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (0);
	p = ft_strdup(s);
	if (!p)
		return (0);
	while (p[i])
	{
		p[i] = f(i, p[i]);
		i++;
	}
	return (p);
}
