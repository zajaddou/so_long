/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:26:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 06:51:18 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(struct s_data *data)
{
	data->door_y = 0;
	data->door_x = 0;
	data->fd = 0;
	data->ow = 0;
	data->h = 0;
	data->w = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->fd = 0;
	data->px = 0;
	data->py = 0;
	data->found_p = 0;
	data->found_c = 0;
	data->found_e = 0;
	data->map = NULL;
	data->map_2d = NULL;
	data->mlx = malloc(sizeof(void *));
    if (!data->mlx)
	    error(" Failed to allocate ( data->mlx ) !");

    data->win = malloc(sizeof(void *));
    if (!data->win)
        error(" Failed to allocate ( data->win ) !");
}

void free2D(char ***map)
{
    int i;
    
    i = 0;
    if (!map || !*map)
        return;
    while ((*map)[i] != NULL)
        free((*map)[i++]);
    free(*map);
    *map = NULL;
}

void error(char *str)
{
	if (!str)
		return ;
	write(1,"\n",1);
	while (*str)
		write(1, str++, 1);
	write(1,"\n\n",2);
    exit (1);
}
