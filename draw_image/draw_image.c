/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:58:52 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/15 20:09:05 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	set_start_pos(t_data *data, char c, int i, int j)
{
	data->map->new_map[i][j] = '0';
	data->orientation = c;
	data->dir_x = ft_start_x(data);
	data->dir_y = ft_start_y(data);
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
	data->pos_x = j;
	data->pos_y = i;
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
			if (data->map->new_map[i][j] == 'N' \
				|| data->map->new_map[i][j] == 'S' \
				|| data->map->new_map[i][j] == 'W' \
				|| data->map->new_map[i][j] == 'E')
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

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x \
		* (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_lines(t_data *data, int x)
{
	int	draw_start;
	int	draw_end;

	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
	draw_start = -data->line_height / 2 + HEIGHT / 2;
	draw_end = data->line_height / 2 + HEIGHT / 2;
	data->tex_x = get_tex_x(data);
	data->tex = &data->textures[data->wall];
	data->mask = 1 << ((sizeof(unsigned int) << 3)
			- clz(TEXHEIGHT));
	draw_line(data, draw_start, draw_end, x);
}

void	draw_image(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		data->camera_x = 2 * x / (double)WIDTH - 1;
		data->ray_dir_x = (data->dir_x + data->plane_x * data->camera_x);
		data->ray_dir_y = (data->dir_y + data->plane_y * data->camera_x);
		data->map_x = (int) data->pos_x;
		data->map_y = (int) data->pos_y;
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
		data->hit = 0;
		steps(data);
		dda(data, x);
		x++;
	}
}
