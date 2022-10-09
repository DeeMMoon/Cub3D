/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_empty_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:10:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/09 13:25:29 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

char	*not_empty_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && !is_empty(line))
	{
		free(line);
		return (not_empty_gnl(fd));
	}
	if (!line)
		return (NULL);
	return (line);
}

int ft_start_x(t_data *data) {
	if (data->orientation == 'S' || data->orientation == 'N')
		return (0);
	if (data->orientation == 'E')
		return (1);
	if (data->orientation == 'W')
		return (-1);
}

int ft_start_y(t_data *data) {
	if (data->orientation == 'E' || data->orientation == 'W')
		return (0);
	if (data->orientation == 'S')
		return (1);
	if (data->orientation == 'N')
		return (-1);
}