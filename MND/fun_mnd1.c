/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 09:56:46 by zajaddou         ###   ########.fr       */
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
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_2d = NULL;
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

static void fill_map(struct s_data *data, int i, int x, int y)
{
    while (y < data->h)
    {
        x = 0;
        while (x <= data->w)
        {
            if (data->map[i] == 'P')
            {
                data->px = x;
                data->py = y;
            }
            if (data->map[i] == 'E')
            {
                data->door_x = x;
                data->door_y = y;
            }
            if (x == data->w)
                (data->map_2d)[y][x] = '\0';
            else
                (data->map_2d)[y][x] = data->map[i];
            i++;
            x++;
        }
        y++;
    }
    (data->map_2d)[y] = NULL;
}


void algo(int y, int x, struct s_data *data)
{
    if (data->map_2d[y][x] == '1' || data->map_2d[y][x] == 'X')
        return;
    if (data->map_2d[y][x] == 'P')
        data->found_p++;
    else if (data->map_2d[y][x] == 'C')
        data->found_c++;
    else if (data->map_2d[y][x] == 'E')
        data->found_e++;
    data->map_2d[y][x] = 'X';
    algo(y+1, x, data);
    algo(y-1, x, data);
    algo(y, x+1, data);
    algo(y, x-1, data);
}

void allocate_2d(struct s_data *data, int i)
{
    data->map_2d = (char **)malloc((data->h + 1) * sizeof(char *));
    if (!data->map_2d)
        error(" Failed to allocate ( data->map_2d ) !");
    i = 0;
    while (i < data->h)
    {
        data->map_2d[i] = (char *)malloc((data->w + 1) * sizeof(char ));
        if (!data->map_2d[i])
           free2D(&data->map_2d);
        i++;
    }
    fill_map(data, 0, 0, 0);
}
