#include "../headers/cub.h"

void	parse_texture(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(1);
	while (i != 6)
	{
		free(line);
		line = not_empty_gnl(fd);
		if (check_config(line, map))
		{
			free (line);
			ft_error("Wrong texture");
		}
		i++;
	}
	if (line)
		free(line);
	if (!check_full_config(map))
		ft_error("Missing required parameters");
	map->floor_color = set_color(map->config->floor);
	map->ceiling_color = set_color(map->config->ceiling);
}

void	parse_map(t_map *map, int fd, char *file)
{
	char	*line;
	char	*first_line;

	line = not_empty_gnl(fd);
	if (!line)
		ft_error ("Map doesn\'t exist");
	first_line = ft_strdup(line);
	while (line)
	{
		if (is_empty(line) == 0 || check_wrong_arg(line))
		{
			free(line);
			ft_error ("Wrong arguments");
		}
		map->width = ft_max(ft_strlen(line), map->width);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	create_new_map(map, file, first_line);
	free(first_line);
}

int	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	parse_texture(map, fd);
	parse_map(map, fd, file);
	return (0);
}

void	create_new_map_two(t_map *map, char *line, int fd)
{
	int	i;

	i = 0;
	while (line)
	{
		map->new_map[i] = get_norm_lenght_line(line, map->width);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	if (check_map(map))
		ft_error("Ivalid map");
	fill_map(map);
}
