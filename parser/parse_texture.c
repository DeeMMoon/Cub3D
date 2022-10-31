#include "../headers/cub.h"

int	check_config_two(char *line, t_map *map, int param_num, char **strs)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 2;
	str = ft_strdup(strs[1]);
	while (strs[i])
	{
		tmp = ft_strjoin(str, strs[i]);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	set_config(param_num, str, map);
	ft_free_arr(strs);
	return (0);
}

int	check_config(char *line, t_map *map)
{
	char	**strs;
	int		param_num;

	strs = ft_split(line, ' ');
	if (!strs)
		return (1);
	param_num = find_param(strs[0]);
	if (param_num == 0)
	{
		ft_free_arr(strs);
		return (1);
	}
	return (check_config_two(line, map, param_num, strs));
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

long	set_color_two(int i, int *rgb, char	**colors, long res)
{
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
	ft_free_arr(colors);
	res = get_color(rgb);
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
	return (set_color_two(i, rgb, colors, res));
}
