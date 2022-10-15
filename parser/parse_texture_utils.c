/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:20:33 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/15 20:19:10 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	find_param(char *line)
{
	if (!ft_strncmp("NO", line, 3))
		return (1);
	else if (!ft_strncmp("SO", line, 3))
		return (2);
	else if (!ft_strncmp("WE", line, 3))
		return (3);
	else if (!ft_strncmp("EA", line, 3))
		return (4);
	else if (!ft_strncmp("F", line, 2))
		return (5);
	else if (!ft_strncmp("C", line, 2))
		return (6);
	return (0);
}

void	set_config(int num, char *str, t_map *map)
{
	if (num == 1)
		map->config->no = str;
	else if (num == 2)
		map->config->so = str;
	else if (num == 3)
		map->config->we = str;
	else if (num == 4)
		map->config->ea = str;
	else if (num == 5)
		map->config->floor = str;
	else if (num == 6)
		map->config->ceiling = str;
}

int	check_full_config(t_map *map)
{
	if (map->config->no == NULL)
		return (0);
	if (map->config->so == NULL)
		return (0);
	if (map->config->we == NULL)
		return (0);
	if (map->config->ea == NULL)
		return (0);
	if (map->config->floor == NULL)
		return (0);
	if (map->config->ceiling == NULL)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	if (map->width - 1 < 3 || map->height < 3)
		return (1);
	if (check_top(map) || check_left(map) || check_bottom(map) \
		|| check_right(map))
		return (1);
	return (0);
}
