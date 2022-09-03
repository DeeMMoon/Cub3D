/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:24:22 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/03 18:41:00 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	util_top(t_map *map, int *j, int *i)
{
	while (*j < map->height)
	{
		if (map->new_map[*j][*i] == '1')
		{
			while (*j < map->height && map->new_map[*j][*i] != ' ')
				(*j)++;
		}
		if (*j < map->height && map->new_map[*j][*i] == ' ')
		{
			if (*j + 1 < map->height && map->new_map[*j + 1][*i] != ' ' \
				&& map->new_map[*j + 1][*i] != '1')
				return (1);
		}
		(*j)++;
	}
	return (0);
}

int	util_left(t_map *map, int *j, int *i, int *k)
{
	while (*j < map->width)
	{
		if (map->new_map[*i][*j] == '1')
		{
			while (map->new_map[*i][*j] && map->new_map[*i][*j] != ' ')
				(*j)++;
		}
		if (map->new_map[*i][*j] && map->new_map[*i][*j] == ' ')
		{
			(*k)++;
			if (map->new_map[*i][*j + 1] && map->new_map[*i][*j + 1] != ' ' \
				&& map->new_map[*i][*j + 1] != '1')
				return (1);
		}
		(*j)++;
	}
	return (0);
}

int	util_bottom(t_map *map, int *j, int *i)
{
	while (*j > 0)
	{
		if (map->new_map[*j][*i] == '1')
		{
			while (*j > 0 && map->new_map[*j][*i] != ' ')
				(*j)--;
		}
		if (*j > 0 && map->new_map[*j][*i] == ' ')
		{
			if ((*j - 1) >= 0 && map->new_map[*j - 1][*i] != ' ' \
				&& map->new_map[*j - 1][*i] != '1')
				return (1);
		}
		(*j)--;
	}
	return (0);
}

int	util_right(t_map *map, int *j, int *i)
{
	while (*j >= 0)
	{
		if (map->new_map[*i][*j] == '1')
		{
			while (*j >= 0 && map->new_map[*i][*j] != ' ')
				(*j)--;
		}
		if (*j >= 0 && map->new_map[*i][*j] == ' ')
		{
			if ((*j - 1) >= 0 && map->new_map[*i][*j - 1] != ' ' \
				&& map->new_map[*i][*j - 1] != '1')
				return (1);
		}
		(*j)--;
	}
	return (0);
}

void fill_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->new_map[i][j])
		{
			if (map->new_map[i][j] == ' ')
				map->new_map[i][j] = '0';
			j++;
		}
		i++;
	}
}