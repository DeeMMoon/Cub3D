#include "../headers/cub.h"

void	texture_calc(t_data *data, int drawStart, int drawEnd)
{
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)TEXWIDTH);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = (TEXWIDTH - data->tex_x - 1);
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = (TEXWIDTH - data->tex_x - 1);
	data->step = 1.0 * TEXHEIGHT / data->line_height;
	data->tex_pos = (drawStart - HEIGHT / 2 \
	+ data->line_height / 2) * data->step;
}

t_img	get_img_from_xpm(t_data *data, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(
			data->ptr,
			path,
			&img.width,
			&img.height);
	if (!img.img)
		ft_error("unable to load image");
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}

void	load_textures(t_data *data)
{
	data->textures[3] = get_img_from_xpm(data, data->map->config->no);
	data->textures[2] = get_img_from_xpm(data, data->map->config->so);
	data->textures[0] = get_img_from_xpm(data, data->map->config->ea);
	data->textures[1] = get_img_from_xpm(data, data->map->config->we);
}

int	clz(unsigned int i)
{
	int				z;
	unsigned int	n;

	z = 0;
	n = 1 << ((sizeof(unsigned int) << 3) - 1);
	while ((!(n & i)) && n > 0)
	{
		n >>= 1;
		z++;
	}
	return (z);
}

int	get_tex_x(t_data *data)
{
	double	wall_x;
	int		tex_x;

	if (data->wall == 2 || data->wall == 3)
		wall_x = data->pos_y + data->perp_wall_dist * data->dir_y;
	else
		wall_x = data->pos_x + data->perp_wall_dist * data->dir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)data->textures[data->wall].width);
	if ((data->wall == 2 || data->wall == 3) && data->dir_x > 0)
		tex_x = (data->textures[3].width - tex_x - 1);
	if ((data->wall == 0 || data->wall == 1) && data->dir_y < 0)
		tex_x = data->textures[0].width - tex_x - 1;
	return (tex_x);
}
