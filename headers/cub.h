/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:06:56 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 18:26:00 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# include "get_next_line.h"
# include "../libft/headers/libft.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
}			t_config;

typedef struct s_map
{
	int			height;
	int			width;
	long		floor_color;
	long		ceiling_color;
	t_config	*config;
}			t_map;

void	ft_error(char *str);
char	*not_empty_gnl(int fd);
char	**ft_split(char const *s, char c);
int		parse_file(t_map *map, char *file);

int		check_full_config(t_map *map);
void	set_config(int num, char *str, t_map *map);
int		find_param(char *line);
long	set_color(char *place);
int		check_config(char *line, t_map *map);

#endif