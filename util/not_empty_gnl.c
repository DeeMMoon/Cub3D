/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_empty_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:10:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 13:21:15 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
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
