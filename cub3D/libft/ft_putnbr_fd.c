#include "headers/libft.h"

void	write_nbr(int n, int fd)
{
	char	*p;

	p = "0123456789";
	if (n / 10)
		write_nbr (n / 10, fd);
	write (fd, &p[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= (-1);
	}
	write_nbr(n, fd);
}
