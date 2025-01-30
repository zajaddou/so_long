/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 00:10:50 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "LIBFT/libft.h"

# include <mlx.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		door_y;
	int		door_x;
	char	*map;
	char	**map_2d;
	char	**map_2d_new;
	char	*map_path;
	int		found_p;
	int		found_c;
	int		found_e;
	int		h;
	int		w;
	int		py;
	int		px;
	int		p;
	int		c;
	int		e;
	int		fd;
	int		ow;
}	t_data;

void	start_game(t_data *data);
void	game_exit(t_data *data);

void	error(char *str);
void	free2d(char ***map);
void	allocate_2d(t_data *data, char ***map);

int		read_file(t_data *data, int fd, char *buff, char *temp);
void	init_map(t_data *data);
void	fill_map(t_data *data, char ***map, int i, int y);

void	algo(int y, int x, t_data *data);

int		path_check(char *path, int len, int i, int e);
int		entity_check(char *line, t_data *data);
void	border_check(struct s_data *data, int i);

int		key_handler(int keycode, t_data *data);

void	first_render(t_data *data, int y, int x, char c);
void	fast_render(t_data *data, int y, int x);
void	set_xmp(t_data *data, char *xmp, int x, int y);
void	set_image(t_data *data, int y, int x, char c);

#endif