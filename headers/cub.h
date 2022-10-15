/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:06:56 by gantedil          #+#    #+#             */
/*   Updated: 2022/10/15 20:18:51 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# include "get_next_line.h"
# include "../libft/headers/libft.h"
# include "../mlx/mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define TEXWIDTH 64
# define TEXHEIGHT 64

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_ESC		53

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

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
	char		**new_map;
	t_config	*config;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_data
{
	t_map			*map;
	t_img			*img;
	void			*ptr;
	void			*win;
	int				**num_map;
	int				step_x;
	int				step_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	char			orientation;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				hit;
	int				side;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	unsigned int	color;
	int				line_height;
	int				wall;
	t_img			textures[4];
	unsigned int	mask;
	t_img			*tex;
}			t_data;

void			ft_error(char *str);
char			*not_empty_gnl(int fd);
char			**ft_split(char const *s, char c);
int				parse_file(t_map *map, char *file);
int				check_map(t_map *map);

int				check_full_config(t_map *map);
void			set_config(int num, char *str, t_map *map);
int				find_param(char *line);
long			set_color(char *place);
int				check_config(char *line, t_map *map);

int				check_wrong_arg(char *str);
char			*get_norm_lenght_line(char *str, int max_len);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				is_empty(char *line);

void			create_new_map(t_map *map, char *file, char *first_line);
int				util_top(t_map *map, int *j, int *i);
int				util_left(t_map *map, int *j, int *i, int *k);
int				util_bottom(t_map *map, int *j, int *i);
int				util_right(t_map *map, int *j, int *i);
void			fill_map(t_map *map);

int				init_data(t_data *data, t_map *map);
void			init_config(t_config *config);
void			init_map(t_map *map, t_config *config);
int				deal_key(int key, t_data *data);
void			draw_image(t_data *data);
void			create_num_map(t_data *data);
void			get_start_pos(t_data *data);

int				ft_start_y(t_data *data);
int				ft_start_x(t_data *data);

unsigned int	mlx_get_pixel(t_data *data, t_img *img, int x, int y);
int				get_tex_x(t_data *data);
int				clz(unsigned int i);
void			load_textures(t_data *data);
t_img			get_img_from_xpm(t_data *data, char *path);
void			texture_calc(t_data *data, int drawStart, int drawEnd);
void			draw_line(t_data *data, int start, int end, int x);
void			steps(t_data *data);
void			dda(t_data *data, int x);
void			draw_lines(t_data *data, int x);
void			my_mlx_pixel_put(t_data *data, int x, \
				int y, unsigned int color);
int				check_top(t_map *map);
int				check_left(t_map *map);
int				check_right(t_map *map);
int				check_bottom(t_map *map);

#endif