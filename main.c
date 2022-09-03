/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:03:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/03 19:23:20 by gantedil         ###   ########.fr       */
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
	map->height = 0;
	map->width = 0;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->config = config;
	map->new_map = NULL;
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
	if (filename[i - 1] != 'b' || filename[i - 2] != 'u' \
		|| filename[i - 3] != 'c' || filename[i - 4] != '.')
		ft_error("File name");
	return (0);
}
int	init_data(t_data *data, t_map *map)
{
	return(1);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_config	*config;
	t_data		*data;

	map = NULL;
	if (argc == 2)
	{
		check_filename(argv[1]);
		config = (t_config *) malloc(sizeof (t_config));
		if (!config)
			ft_error("Init faled");
		init_config(config);
		map = (t_map *) malloc (sizeof (t_map));
		if (!map)
			ft_error("Init faled");
		init_map(map, config);
		parse_file(map, argv[1]);
		data = (t_data *) malloc(sizeof (t_data));
		if (!init_data(data, map))
			ft_error("Init faled");
	}
	return (0);
}
