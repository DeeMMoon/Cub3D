#include "headers/libft.h"

static long	ft_cycle(const char *str, long number)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

static long	ft_la(unsigned long len, long number, const char *str, int znak)
{
	if (len == 19
		&& (ft_strncmp(str, "9223372036854775807L", len) >= 0
			|| ft_strncmp(str, "-9223372036854775807L - 1L", len) <= 0))
	{
		if (*(str + 19) == '7' || *(str + 19) == '8' || znak == 1)
			return (9223372036854775807L);
		else if (*(str + 19) == '8' || *(str + 19) == '9' || znak == -1)
			return (-9223372036854775807L - 1L);
		else
		{
			return (ft_cycle(str, number));
		}
	}
	else if (len > 19)
	{
		if (znak == -1)
			return (-9223372036854775807L - 1L);
		else
			return (9223372036854775807L);
	}
	else
	{
		return (ft_cycle(str, number));
	}
}

static int	ft_len(const char *str)
{
	int	k;

	k = 0;
	while (ft_isdigit(str[k]) == 1)
	{
		k++;
	}
	return (k);
}

int	ft_atoi(const char *str)
{
	long	number;
	int		znak;
	int		i;
	size_t	len;

	i = 0;
	number = 0;
	znak = 1;
	while ((str[i] == '\n') || (str[i] == ' ') || (str[i] == '\t')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		str++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		znak *= -1;
		i++;
	}
	len = ft_len(&str[i]);
	number = ft_la(len, number, &str[i], znak);
	number *= znak;
	return ((int)number);
}
