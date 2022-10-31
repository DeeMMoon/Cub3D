#include "headers/libft.h"

char	*ft_strdup(const char *str)
{
	char		*p;
	size_t		len;
	size_t		i;

	len = ft_strlen(str);
	i = 0;
	p = (char *) malloc(sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
