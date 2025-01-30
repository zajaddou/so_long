/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 14:37:11 by zajaddou         ###   ########.fr       */
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

struct s_data
{
	void *mlx;
    void *win;
	
	int	 door_y;
	int  door_x;
	
	char	*map;
	char	**map_2d;
	char	*map_path;

	int 	found_p;
	int 	found_c;
	int 	found_e;
	int 	open;
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

void error(char *str);
void free2D(char ***map);
void allocate_2d(struct s_data *data, int i);
void init_map(struct s_data *data);
int valid_path(char *path, int len, int i, int e);
int	read_file(struct s_data *data, int fd, char *buff, char *temp);
void border_check(struct s_data *data, int i);
void algo(int y, int x, struct s_data *data);
int  move_player(struct s_data *data, int keycode);
int  start_game(struct s_data *data);
void render_game(struct s_data *data, int y, int x);

#endif