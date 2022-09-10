/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:48:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/10 21:11:58 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

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

int	init_data(t_data *data, t_map *map)
{
	data->map = map;
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, HEIGHT, WIDTH, "CUB_3D");
	data->img = (t_img *) malloc(sizeof (t_img));
	if (!data->img)
		return (0);
	data->img->img = mlx_new_image(data->ptr, HEIGHT, WIDTH);
	data->img->addr = mlx_get_data_addr(data->img->img, &(data->img->bits_per_pixel) \
	, &(data->img->line_length), &(data->img->endian));
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->time = 0;
	data->oldTime = 0;

	return(1);
}

int	deal_key(int key, t_data *data)
{
	// if (key == 123)
	// 	map->shift_x -= 10;
	// if (key == 124)
	// 	map->shift_x += 10;
	// if (key == 126)
	// 	map->shift_y -= 10;
	// if (key == 125)
	// 	map->shift_y += 10;
	// if (key == 69)
	// 	map->zoom += 2;
	// if (key == 78 && map->zoom >= 3)
	// 	map->zoom -= 2;
	 if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	mlx_clear_window(data->ptr, data->win);
	mlx_destroy_image(data->ptr, data->img->img);
	data->img->img = mlx_new_image(data->ptr, HEIGHT, WIDTH);
	//drow_map(map);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
	return (0);
}