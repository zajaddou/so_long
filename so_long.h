/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 04:57:59 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "LIBFT/libft.h"

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include <stdio.h>

struct s_render
{
	int  h;
	int	 w;
    int  py;
    int  px;
	int	 door_y;
	int  door_x;
	int	 coins;
	
    void *mlx;
    void *win;
	char **map_2d;
};

struct s_map
{
	int	 door_y;
	int  door_x;
	
	char	*map;
	char	**map_2d;
	char	*map_path;

	int 	found_p;
	int 	found_c;
	int 	found_e;
	
	int		h;
	int		w;
	int		py;
	int		px;
	int		p;
	int		c;
	int		e;
	int		fd;
	int		ow;
	int 	i;
};

void invalid_map();
void invalid_game();
void system_error();
void free2D(char ***map);
void swap_data(struct s_map *data,struct s_render *render);
void allocate_2d(struct s_map *data, int i);
int	 init_render(struct s_render *render);
void init_map(struct s_map *data);
int  validpath(char *path);
int	 read_file(struct s_map *data, int fd);
void border_check(struct s_map *data, int i);
void algo(int y, int x, struct s_map *data);
int  move_player(struct s_render *render, int keycode);
int  joingame(struct s_map *data, struct s_render *render);
void render_game(struct s_render *render, int y, int x);

#endif