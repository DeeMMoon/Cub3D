/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:03:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/15 16:44:19 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	init_map(t_map *map, t_config *config)
{
	map->height = -1;
	map->width = -1;
	map->config = config;
}

void	init_config(t_config *config)
{
	config->ceiling = NULL;
	config->floor = NULL;
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'c' || filename[i - 2] != 'u' \
		|| filename[i - 3] != 'b' || filename[i - 4] != '.')
		ft_error("File name");
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_config	*config;

	map = NULL;
	if (argc == 2)
	{
		check_filename(argv[1]);
		config = (t_config *) malloc(sizeof (t_config));
		if (!config)
			ft_errors("Init faled");
		init_config(config);
		map = (t_map *) malloc (sizeof (t_map));
		if (!map)
			ft_errors("Init faled");
		init_map(map, config);
		parse_file(map, argv[1]);
	}
	return (0);
}
