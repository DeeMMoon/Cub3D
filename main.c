/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:03:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/09 12:48:10 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->ptr, data->img->img);
	mlx_destroy_window(data->ptr, data->win);
	exit(EXIT_SUCCESS);
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
		get_start_pos(data);
		create_num_map(data);
		draw_image(data);
		mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
		mlx_hook(data->win, 17, 0L, close_win, data);
		mlx_key_hook(data->win, deal_key, data);
		mlx_loop(data->ptr);
	}
	return (0);
}
