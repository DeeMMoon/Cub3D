/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:19:13 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 18:31:42 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	check_config(char *line, t_map *map)
{
	char	**strs;
	char	*str;
	int		param_num;
	int		i;

	strs = ft_split(line, ' ');
	if (!strs)
		return (1);
	param_num = find_param(strs[0]);
	if (param_num == 0)
		return (1);
	i = 2;
	str = strs[1];
	while (strs[i])
	{
		str = ft_strjoin(str, strs[i]);
		i++;
	}
    //очистить strs
	set_config(param_num, str, map);
	return (0);
}

long	get_color(int *rgb)
{
	long	color;
	int		i;

	i = 0;
	color = 0;
	while (rgb[i] != -1)
	{
		color <<= 8;
		color += rgb[i];
		i++;
	}
	free(rgb);
	return (color);
}

long	set_color(char *place)
{
	int		*rgb;
	char	**colors;
	int		i;
	long	res;

	i = 0;
	colors = ft_split(place, ',');
	if (!colors)
		ft_error("Wrong param color");
	while (colors[i])
		i++;
	if (i != 3)
		ft_error("Wrong param color");
	rgb = malloc(sizeof(int) * 4);
	i = 0;
	while (i <= 3 && colors[i])
	{
		rgb[i] = ft_atoi(colors[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
			ft_error("Wrong param color");
		i++;
	}
	rgb[i] = -1;
	i = 0;
    //очистить colors
	res = get_color(rgb);
	return (res);
}