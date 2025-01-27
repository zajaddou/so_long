/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 04:48:44 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void fill_map(struct s_map *data)
{
    int i = 0;
    int x = 0;
    int y = 0;

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

static void algo(int y, int x, struct s_map *data)
{
    if (data->map_2d[y][x] == '1' || data->map_2d[y][x] == 'V')
        return;
    
    if (data->map_2d[y][x] == 'P')
        data->found_p++;
    else if (data->map_2d[y][x] == 'C')
        data->found_c++;
    else if (data->map_2d[y][x] == 'E')
        data->found_e++;

    data->map_2d[y][x] = 'V';
    
    algo(y+1, x, data);
    algo(y-1, x, data);
    algo(y, x+1, data);
    algo(y, x-1, data);
} 

void printmap(struct s_map *data)
{
    int y;
    int x;

    x = 0;
    y = 0;
    
    while (y < data->h)
    {
        x = 0;
        while (x < data->w)
        {
           	if (data->map_2d[y][x] == '1' )
			    printf("%s", "▉");
            else if (data->map_2d[y][x] == '0')
                printf("%c", ' ');
            else
			    printf("%c", data->map_2d[y][x]);
            x++;
        }
        printf("\n");
		y++;
	}
    printf("\n");
}

int initmap(struct s_map *data)
{
    int i;
    if (isvalid(data))
        return (1);

    i = 0;
    data->map_2d = (char **)malloc((data->h + 1) * sizeof(char *));
    
    while (i < data->h)
        data->map_2d[i++] = (char *)malloc((data->w + 1) * sizeof(char ));
        
    fill_map(data);

    if (border_check(data))
        return (1);

    printmap(data);

    algo(data->py, data->px, data);

    if (!(data->found_p == data->p) && (data->found_c == data->c) && (data->found_e == data->e))
        return (1);
    
    return (0);
}
