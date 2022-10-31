#include "headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	size_t			size;

	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = (char *) malloc (sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	i = start;
	size = 0;
	while (s[i] && (size < len))
	{
		p[size] = s[i];
		size++;
		i++;
	}
	p[size] = '\0';
	return (p);
}
