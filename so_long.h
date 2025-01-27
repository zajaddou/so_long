/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/28 07:25:58 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "LIBFT/libft.h"

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

struct s_render
{
	int  h;
	int	 w;
    int  py;
    int  px;
    void *mlx;
    void *win;
	char **map_2d;
};

struct s_map
{
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

int  is_valid(struct s_map *data);
int  init_map(struct s_map *data);
int  move_player(struct s_render *render, int keycode);
int  joingame(struct s_map *data, struct s_render *render);
void render_game(struct s_render *render, int y, int x);
void print_map(struct s_map *data, char ***map, int y, int x);

#endif