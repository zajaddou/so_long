/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:18:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 03:43:57 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "LIBFT/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

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
};

struct player
{
	int x;
	int y;
};

int isvalid(struct s_map *data);
int initmap(struct s_map *data);

#endif