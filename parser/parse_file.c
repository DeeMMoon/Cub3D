/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:09:25 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/15 20:34:34 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

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

int	check_config(char *line)
{
	int		i;
	char	**strs;
	int		param_num;

	i = 0;
	strs = ft_split(line, ' ');
	param_num = find_param(strs[0]);
	if (param_num == 0)
		return (1);
	else
	{
		//Назначить адрес до текстуры в переменную config
	}
	while (strs[i])
		i++;
	if (i > 2)
		return (1);
	return (0);
}

void	parse_texture(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i != 6)
	{
		line = not_empty_gnl(fd);
		if (!check_config(line))
			ft_error("Wrong texture");
	}
}

int	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	parse_texture(map, fd);
	return (0);
}
