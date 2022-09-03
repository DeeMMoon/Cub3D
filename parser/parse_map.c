/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:09 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/03 18:42:49 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (map->new_map[i][map->width - 1] != ' ' 
			&& map->new_map[i][map->width - 1] != '1')
			return (1);
		j = map->width - 1;
		if (util_right(map, &j, &i))
			return (1);
		i++;
	}
	return (0);
}
	
int	check_map(t_map *map)
{
	if (map->width - 1 < 3 || map->height < 3)
		return (1);
	if (check_top(map)|| check_left(map) || check_bottom(map) \
		|| check_right(map))
		return (1);
	return (0);
}

void	create_new_map(t_map *map, char *file, char *first_line)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	map->new_map = (char **) malloc(sizeof(char *) * map->height);
	line = not_empty_gnl(fd);
	while (ft_strncmp(line, first_line, ft_strlen(first_line)) != 0)
		line = not_empty_gnl(fd);
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
