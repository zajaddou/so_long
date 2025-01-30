/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 06:50:37 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void fill_map(struct s_data *data, char ***map, int x, int y)
{
    int i;

    i = 0;
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
                (*map)[y][x] = '\0';
            else
                (*map)[y][x] = data->map[i];
            i++;
            x++;
        }
        y++;
    }
    (*map)[y] = NULL;
}
void border_check(struct s_data *data, int i)
{
    while (i < data->h)
        if (data->map_2d[i][0] != '1' || data->map_2d[i++][data->h-1] != '1')
            error(" invalid border !");
    i = 0;
    while (i < data->w)
       if (data->map_2d[0][i] != '1' || data->map_2d[data->w-1][i++] != '1')
            error(" invalid border !");
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
    fill_map(data, &data->map_2d, 0, 0);
}
