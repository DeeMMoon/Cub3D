/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:50:24 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/17 19:08:48 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i < max_len - 1)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	free (str);
	return (line);
}

