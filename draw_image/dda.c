#include "../headers/cub.h"

void	draw_line(t_data *data, int start, int end, int x)
{
	int		y;
	int		ty;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		texture_calc(data, start, end);
		if (y < start)
			my_mlx_pixel_put(data, x, y, data->map->ceiling_color);
		else if (y > end)
			my_mlx_pixel_put(data, x, y, data->map->floor_color);
		else
		{
			ty = (((y - start) * data->mask / data->line_height) \
				& (data->mask - 1)) * ((double)data->textures->height \
				/ data->mask);
			color = mlx_get_pixel(data, data->tex, data->tex_x, ty);
			my_mlx_pixel_put(data, x, y, color);
		}
		y++;
	}
}

void	steps(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 \
		- data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 \
		- data->pos_y) * data->delta_dist_y;
	}
}

void	check_wall(t_data *data)
{
	if (data->num_map[data->map_y][data->map_x] > 0)
	{
		data->hit = 1;
		if (data->side == 0 && data->ray_dir_x > 0)
			data->wall = 0;
		else if (data->side == 0 && data->ray_dir_x <= 0)
			data->wall = 1;
		else if (data->side == 1 && data->ray_dir_y > 0)
			data->wall = 2;
		else if (data->side == 1 && data->ray_dir_y <= 0)
			data->wall = 3;
	}
}

void	dda(t_data *data, int x)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		check_wall(data);
	}
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	draw_lines(data, x);
}

unsigned int	mlx_get_pixel(t_data *data, t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
