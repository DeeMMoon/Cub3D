#include "../headers/cub.h"

int	check_top(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->new_map[0][i])
	{
		if (map->new_map[0][i] != ' ' && map->new_map[0][i] != '1')
			return (1);
		j = 0;
		if (util_top(map, &j, &i))
			return (1);
		i++;
	}
	return (0);
}

int	check_left(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < map->height)
	{
		if (map->new_map[i][0] != ' ' && map->new_map[i][0] != '1')
			return (1);
		j = 0;
		k = 0;
		if (util_left(map, &j, &i, &k))
			return (1);
		if (k > map->width - 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_bottom(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->new_map[map->height - 1][i])
	{
		if (map->new_map[map->height - 1][i] != ' ' \
			&& map->new_map[map->height - 1][i] != '1')
			return (1);
		j = map->height - 1;
		if (util_bottom(map, &j, &i))
			return (1);
		i++;
	}
	return (0);
}

int	check_right(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (map->new_map[i][map->width - 1] != ' ' \
			&& map->new_map[i][map->width - 1] != '1')
			return (1);
		j = map->width - 1;
		if (util_right(map, &j, &i))
			return (1);
		i++;
	}
	return (0);
}

void	create_new_map(t_map *map, char *file, char *first_line)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	map->new_map = (char **) malloc(sizeof(char *) * map->height);
	line = not_empty_gnl(fd);
	while (ft_strncmp(line, first_line, ft_strlen(first_line)) != 0)
	{
		free(line);
		line = not_empty_gnl(fd);
	}
	create_new_map_two(map, line, fd);
}
