/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:03:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/09 20:53:51 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

void	ft_errors(int error_num)
{
	if (error_num == 1)
	{
		write(1, "Map is not create\n", 18);
		exit(EXIT_FAILURE);
	}
	if (error_num == 2)
	{
		write(1, "Incorrect number of arguments\n", 30);
		exit(EXIT_FAILURE);
	}
	if (error_num == 3)
	{
		write(1, "File cannot be read\n", 20);
		exit(EXIT_FAILURE);
	}
	if (error_num == 4)
	{
		write(1, "Map error\n", 10);
		exit(EXIT_FAILURE);
	}
}

void	init_struct(t_map *map)
{
	/* TODO */
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'c' || filename[i - 2] != 'u' \
		|| filename[i - 3] != 'b' || filename[i - 4] != '.')
	{
		write(1, "Error file name\n", 16);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc == 2)
	{
		check_filename(argv[1]);
		map = (t_map *) malloc (sizeof (t_map));
		if (!map)
			ft_errors(1);
		init_struct(map);
		parse_file(map, argv[1]);
	}
	return (0);
}