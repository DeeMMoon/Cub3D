/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:58:52 by gantedil          #+#    #+#             */
/*   Updated: 2022/09/10 21:11:55 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	set_start_pos(t_data *data, char c, int i, int j)
{
	data->map->new_map[i][j] = '0';
	data->orientation = c;
	data->posX = j;
	data->posY = i;
}

void	get_start_pos(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i <= data->map->height - 1)
	{
		j = 0;
		while (data->map->new_map[i][j])
		{
			if (data->map->new_map[i][j] == 'N' || data->map->new_map[i][j] == 'S' \
				|| data->map->new_map[i][j] == 'W' || data->map->new_map[i][j] == 'E')
			{
				if (flag == 1)
					ft_error("Use more one person");
				set_start_pos(data, data->map->new_map[i][j], i, j);
				flag = 1;
			}
			j++;
		}
		i++;
	}	
}


void	draw_image(t_data *data)
{
	int	x;

	x = 0;
	get_start_pos(data);
	while (x < WIDTH)
	{
		data->cameraX = 2 * x / (double)WIDTH - 1;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		data->mapX = (int) data->posX;
		data->mapY = (int) data->posY;
		if (data->rayDirX == 0)
			data->deltaDistX = HUGE_VAL;
		else
			data->deltaDistX = fabs(1 / data->rayDirX);
		if (data->rayDirY == 0)
			data->deltaDistY = HUGE_VAL;
		else
			data->deltaDistY = fabs(1 / data->rayDirY);
		//steps
	}
	// printf("%f\n", data->posX);
	// printf("%f\n", data->posY);
	// printf("%c\n", data->orientation);
}