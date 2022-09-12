/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:48:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/12 19:55:57 by gantedil         ###   ########.fr       */
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
	data->num_map = NULL;
	return(1);
}

int	deal_key(int key, t_data *data)
{
	if (key == KEY_A)
	{
	}
	if (key == KEY_D)
	{}
	if (key == KEY_S)
	{}
	if (key == KEY_W)
	{	
		printf("YES\n");	
		if(data->num_map[(int)(data->posY + data->dirY * MOVE_SPEED)][(int) data->posX] == 0)
			data->posY += data->dirY * MOVE_SPEED;
		if(data->num_map[(int) data->posY][(int)(data->posX + data->dirX * MOVE_SPEED)] == 0)
			data->posX += data->dirX * MOVE_SPEED;
	}
	if (key == KEY_LEFT)
	{}
	if (key == KEY_RIGHT)
	{}
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	mlx_destroy_image(data->ptr, data->img->img);
	data->img->img = mlx_new_image(data->ptr, HEIGHT, WIDTH);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_image(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
	return (0);
}