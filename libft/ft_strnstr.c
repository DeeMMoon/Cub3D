#include "headers/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*p;
	size_t	i;
	size_t	k;
	size_t	size_little;

	p = (char *) big;
	size_little = ft_strlen(little);
	if (size_little == 0 || little == big)
		return (p);
	i = 0;
	while (p[i] && (i < len))
	{
		k = 0;
		while (little[k] && p[i + k] && (i + k) < len
			&& p[i + k] == little[k])
			k++;
		if (k == size_little)
			return (&p[i]);
		i++;
	}
	return (0);
}
