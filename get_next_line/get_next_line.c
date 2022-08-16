/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:55 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 12:51:53 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*get_remain(char *str)
{
	char	*p;
	int		i;
	int		k;

	if (!str)
		return (0);
	i = 0;
	k = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	p = (char *) malloc (sizeof(char) * (ft_strlen(str) - i + 1));
	if (!p)
		return (0);
	i++;
	while (str[i])
		p[k++] = str[i++];
	p[k] = '\0';
	free(str);
	return (p);
}

char	*get_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	p = (char *) malloc (sizeof(char) * (i + 2));
	if (!p)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && str[i - 1] == ' ')
		p[(i--) - 1] = '\n';
	if (str[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

int	is_read(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain;
	char		buff[BUFFER_SIZE + 1];
	int			reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reader = 1;
	while (is_read(remain) && reader != 0)
	{
		reader = read (fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (0);
		buff[reader] = '\0';
		remain = str_join(remain, buff);
	}
	if (!remain)
		return (0);
	line = get_line(remain);
	remain = get_remain(remain);
	return (line);
}
