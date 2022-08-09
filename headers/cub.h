#ifndef	CUB_H
# define CUB_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

typedef	struct	s_map
{
	int		height;
	int		width;
}			t_map;

#endif