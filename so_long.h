/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 18:36:12 by zajaddou         ###   ########.fr       */
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
	int		i;
}	t_data;

void	error(char *str);
void	free2d(char ***map);
void	allocate_2d(t_data *data, char ***map);
void	init_map(t_data *data);
void	fill_map(t_data *data, char ***map, int i, int y);
int		read_file(t_data *data, int fd, char *buff, char *temp);
int		valid_path(char *path, int len, int i, int e);
void	border_check(struct s_data *data, int i);
void	algo(int y, int x, t_data *data);
void	set_block(t_data *data, char *xmp, int x, int y);
int		move_player(t_data *data, int keycode);
void	start_game(t_data *data);

void	first_render(t_data *data, int y, int x, char c);

void	set_image(t_data *data, int y, int x, char c);
void	fast_render(t_data *data, int y, int x);

#endif