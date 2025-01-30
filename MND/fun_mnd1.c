/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 18:34:54 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_data *data)
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
	data->map_2d_new = NULL;
}

void	free2d(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while ((*map)[i] != NULL)
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

void	fill_map(t_data *data, char ***map, int i, int y)
{
	int x;
	
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
			(*map)[y][x] = '\0';
			if (x != data->w)
				(*map)[y][x] = data->map[i];
			x++;
			i++;
		}
		y++;
	}
    (*map)[y] = NULL;
}

void	algo(int y, int x, t_data *data)
{
	if (data->map_2d[y][x] == '1' || data->map_2d[y][x] == 'X')
		return ;
	if (data->map_2d[y][x] == 'P')
		data->found_p++;
	else if (data->map_2d[y][x] == 'C')
		data->found_c++;
	else if (data->map_2d[y][x] == 'E')
		data->found_e++;
	data->map_2d[y][x] = 'X';
	algo(y + 1, x, data);
	algo(y - 1, x, data);
	algo(y, x + 1, data);
	algo(y, x - 1, data);
}

void allocate_2d(t_data *data, char ***map)
{
    int i;

    if (*map != NULL)
        error(" You have data ( data->map_2d ) !");

    *map = (char **)malloc((data->h + 1) * sizeof(char *));
    if (!*map)
        error(" Failed to allocate ( data->map_2d ) !");

    i = 0;
    while (i < data->h)
    {
        (*map)[i] = (char *)malloc((data->w + 1) * sizeof(char));
        if (!(*map)[i])
        {
            free2d(map);
            return;
        }
        i++;
    }
    (*map)[data->h] = NULL;
}

