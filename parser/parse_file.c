/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:09:25 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 18:51:13 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	parse_texture(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i != 6)
	{
		line = not_empty_gnl(fd);
		printf("line = %s\n", line);
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

void	print_info(t_map *map)
{
	printf("NO = %s\n", map->config->no);
	printf("SO = %s\n", map->config->so);
	printf("WE = %s\n", map->config->we);
	printf("EA = %s\n", map->config->ea);
	printf("F = %s\n", map->config->floor);
	printf("C = %s\n", map->config->ceiling);
	printf("F_COLOR = %ld\n", map->floor_color);
	printf("C_COLOR = %ld\n", map->ceiling_color);
}

int	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	parse_texture(map, fd);
	print_info(map);
	parse_map(map, fd);
	return (0);
}
