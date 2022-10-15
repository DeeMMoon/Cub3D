/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:11:04 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/15 20:19:25 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	rotate_keys_two(int key, t_data *data, \
		double old_dir_x, double old_plane_x)
{
	if (key == KEY_LEFT)
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-ROT_SPEED) \
		- data->dir_y * sin(-ROT_SPEED);
		data->dir_y = old_dir_x * sin(-ROT_SPEED) \
		+ data->dir_y * cos(-ROT_SPEED);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-ROT_SPEED) \
		- data->plane_y * sin(-ROT_SPEED);
		data->plane_y = old_plane_x * sin(-ROT_SPEED) \
		+ data->plane_y * cos(-ROT_SPEED);
	}
}

void	rotate_keys(int key, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == KEY_RIGHT)
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(ROT_SPEED) \
		- data->dir_y * sin(ROT_SPEED);
		data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(ROT_SPEED) \
		- data->plane_y * sin(ROT_SPEED);
		data->plane_y = old_plane_x * sin(ROT_SPEED) \
		+ data->plane_y * cos(ROT_SPEED);
	}
	rotate_keys_two(key, data, old_dir_x, old_plane_x);
}

void	check_a_d(int key, t_data *data)
{
	if (key == KEY_A)
	{
		if (data->num_map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x \
		* MOVE_SPEED + data->dir_y * MOVE_SPEED)] == 0)
			data->pos_x += data->dir_y * MOVE_SPEED;
		if (data->num_map[(int)(data->pos_y + data->dir_y * MOVE_SPEED \
		- data->dir_x * MOVE_SPEED)][(int)(data->pos_x)] == 0)
			data->pos_y -= data->dir_x * MOVE_SPEED;
	}
	if (key == KEY_D)
	{
		if (data->num_map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x \
		* MOVE_SPEED - data->dir_y * MOVE_SPEED)] == 0)
			data->pos_x -= data->dir_y * MOVE_SPEED;
		if (data->num_map[(int)(data->pos_y - data->dir_y * MOVE_SPEED \
		+ data->dir_x * MOVE_SPEED)][(int)((int) data->pos_x)] == 0)
			data->pos_y += data->dir_x * MOVE_SPEED;
	}
}

void	check_w_s(int key, t_data *data)
{
	if (key == KEY_W)
	{	
		if (data->num_map[(int)(data->pos_y + data->dir_y \
		* MOVE_SPEED)][(int)data->pos_x] == 0)
			data->pos_y += data->dir_y * MOVE_SPEED;
		if (data->num_map[(int)data->pos_y][(int)(data->pos_x \
		+ data->dir_x * MOVE_SPEED)] == 0)
			data->pos_x += data->dir_x * MOVE_SPEED;
	}
	if (key == KEY_S)
	{		
		if (data->num_map[(int)(data->pos_y - data->dir_y \
		* MOVE_SPEED + MOVE_SPEED)][(int)data->pos_x] == 0)
			data->pos_y -= data->dir_y * MOVE_SPEED;
		if (data->num_map[(int)data->pos_y][(int)(data->pos_x \
		- data->dir_x * MOVE_SPEED + MOVE_SPEED)] == 0)
			data->pos_x -= data->dir_x * MOVE_SPEED;
	}
}

int	deal_key(int key, t_data *data)
{
	check_a_d(key, data);
	check_w_s(key, data);
	rotate_keys(key, data);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	mlx_destroy_image(data->ptr, data->img->img);
	data->img->img = mlx_new_image(data->ptr, HEIGHT, WIDTH);
	data->img->addr = mlx_get_data_addr(data->img->img, \
	&data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_image(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
	return (0);
}
