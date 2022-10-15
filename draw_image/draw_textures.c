/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:38:10 by utawana           #+#    #+#             */
/*   Updated: 2022/10/15 19:11:40 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	texture_calc(t_data *data, int drawStart, int drawEnd)
{
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor(data->wallX);
	data->texX = (int)(data->wallX * (double)TEXWIDTH);
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = (TEXWIDTH - data->texX - 1);
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = (TEXWIDTH - data->texX - 1);
	data->step = 1.0 * TEXHEIGHT / data->lineHeight;
	data->texPos = (drawStart - HEIGHT / 2 + data->lineHeight / 2) * data->step;
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

void load_textures(t_data *data)
{
	data->textures[0] = get_img_from_xpm(data, data->map->config->no);
	data->textures[1] = get_img_from_xpm(data, data->map->config->so);
	data->textures[2] = get_img_from_xpm(data, data->map->config->ea);
	data->textures[3] = get_img_from_xpm(data, data->map->config->we);
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
		wall_x = data->posY + data->perpWallDist * data->dirY;
	else
		wall_x = data->posX + data->perpWallDist * data->dirX;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)data->textures[data->wall].width);
	if ((data->wall == 2 || data->wall == 3) && data->dirX > 0)
		tex_x = (data->textures[3].width - tex_x - 1);
	if ((data->wall == 0 || data->wall == 1) && data->dirY < 0)
		tex_x = data->textures[0].width - tex_x - 1;
	return (tex_x);
}

unsigned int	mlx_get_pixel(t_data *data, t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

