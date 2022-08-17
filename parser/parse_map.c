/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:09 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/17 21:25:58 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	check_top(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map->new_map[0][i])
	{
		if (map->new_map[0][i] != ' ' && map->new_map[0][i] != '1')
			return (1);
		j = 1;
		while (j < map->height)
		{
			if (map->new_map[j][i] == '1')
			{
				while (j < map->height && map->new_map[j][i] != ' ')
					j++;
			}
			if (j < map->height && map->new_map[j][i] == ' ')
			{
				k++;
				if (j + 1 < map->height && map->new_map[j + 1][i] != ' ' \
					&& map->new_map[j + 1][i] != '1')
					return (1);
			}
			j++;
		}
		if (k == map->height)
			return (1);
		i++;
	}
	return (0);
}

// int	check_left(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map->height)
// 	{
// 		if (map->new_map[i][0] != ' ' && map->new_map[i][0] != '1')
// 			return (1);
// 		if (map->new_map[i][0] == ' ')
// 		{
// 			j = 1;
// 			while (map->new_map[i][j] && map->new_map[i][j] != '1')
// 			{
// 				if (map->new_map[i][j] != ' ')
// 					return (1);
// 				j++;
// 			}
// 			if (j == map->width)
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	check_bottom(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map->new_map[map->height - 1][i])
// 	{
// 		if (map->new_map[map->height - 1][i] != ' ' \
// 			&& map->new_map[map->height - 1][i] != '1')
// 			return (1);
// 		if (map->new_map[map->height - 1][i] == ' ')
// 		{
// 			j = map->height - 2;
// 			while (j >= 0 && map->new_map[j][i] != '1')
// 			{
// 				if (map->new_map[j][i] != ' ')
// 					return (1);
// 				j--;
// 			}
// 			if (j == 0)
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

/* Передалать проверки границ слева и снизу по аналогии с проверкой сверху
	Написать проверку границы справа
	Но сначала подогнать под норму функцию проверки сверху
*/

int	check_map(t_map *map)
{
	if (check_top(map))
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
	i = 0;
	while (i < map->height)
	{
		printf("|%s|\n", map->new_map[i]);
		i++;
	}
	if (line)
		free(line);
	if (check_map(map))
		ft_error("Ivalid map");
}
