/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/26 20:51:45 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void m2d(struct s_map *data)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (y < data->h)
    {
        x = 0;
        while (x < data->w+1)
        {
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
static int border_check(struct s_map *data)
{
    int i;

    i = 0;
    while (i < data->h)
        if (data->map_2d[i][0] != '1' || data->map_2d[i++][data->w-1] != '1')
            return (1);
    i = 0;
    while (i < data->w)
        if (data->map_2d[0][i] != '1' || data->map_2d[data->h-1][i++] != '1')
            return (1);
    return (0);
}


static void algo(int x,int y, struct s_map *data)
{
    if (data->map_2d[x][y] == '1' || data->map_2d[x][y] == 'V')
        return;

    if (data->map_2d[x][y] == 'P')
        data->found_p++;

    if (data->map_2d[x][y] == 'C')
        data->found_c++;

    if (data->map_2d[x][y] == 'E')
        data->found_e++;

    data->map_2d[x][y] = 'V';

    algo(x, y+1, data);
    algo(x, y-1, data);
    algo(x+1, y, data);
    algo(x-1, y, data);
}

int initmap(struct s_map *data)
{
    if (isvalid(data))
        return (printf("\n%s\n\n",  " Invalid Map ! "), 1);

    int i;
    int y;
    int x;

    x = 0;
    i = 0;
    y = 0;

    data->map_2d = (char **)malloc((data->h + 1) * sizeof(char *));

    while (i < data->h)
        data->map_2d[i++] = (char *)malloc((data->w + 1) * sizeof(char ));

    m2d(data);
        
    if (border_check(data))
        return (printf("\n%s\n\n",  " Invalid Map ! "), 1);
        
    algo(1, 1, data);

    if (data->p != data->found_p || data->c != data->found_c || data->e != data->found_e)
        return (printf("\n%s\n\n",  " Invalid Game ! "), 1);
    
    return (0);
}