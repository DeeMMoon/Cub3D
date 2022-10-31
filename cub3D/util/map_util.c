#include "../headers/cub.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	check_wrong_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0' \
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' \
			&& str[i] != 'E' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_norm_lenght_line(char *str, int max_len)
{
	char	*line;
	int		i;

	line = (char *) malloc (sizeof(char) * (max_len));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	while (i < max_len)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	free (str);
	return (line);
}

void	create_num_map(t_data *data)
{
	int	i;
	int	j;

	data->num_map = (int **) malloc(sizeof(int *) * (data->map->height + 1));
	if (!data->num_map)
		ft_error("Fault init");
	i = -1;
	while (++i < data->map->height)
	{
		data->num_map[i] = (int *) malloc(sizeof(int) * (data->map->width + 1));
		if (!data->num_map[i])
			ft_error("Fault init");
	}
	i = -1;
	while (++i <= data->map->height - 1)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (data->map->new_map[i][j] == '1')
				data->num_map[i][j] = 1;
			else
				data->num_map[i][j] = 0;
		}
	}
}
