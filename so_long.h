/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 14:38:04 by zajaddou         ###   ########.fr       */
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
    int  py;
    int  px;
    void *mlx;
    void *win;
	void *imgs[4];
    char *paths[5];
};

struct s_map
{
	char	*map;
	char	**map_2d_real;
	char	**map_2d_algo;
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

int is_valid(struct s_map *data);
int initmap(struct s_map *data);
int joingame(struct s_map *data, struct s_render *render);

#endif