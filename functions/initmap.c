/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 11:14:56 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void fill_map(struct s_map *data, char ***map, int x, int y)
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
static int border_check(struct s_map *data, int i)
{
    while (i < data->h)
        if (data->map_2d_algo[i][0] != '1' || data->map_2d_algo[i++][data->w-1] != '1')
            return (1);
    i = 0;
    while (i < data->w)
        if (data->map_2d_algo[0][i] != '1' || data->map_2d_algo[data->h-1][i++] != '1')
            return (1);
    return (0);
}

void print_map(struct s_map *data, char ***map, int y, int x)
{
    while (y < data->h)
    {
        x = 0;
        while (x < data->w)
        {
           	if ((*map)[y][x] == '1' )
			    printf("%s", "▉▉");
            else if ((*map)[y][x] == '0')
                printf("%s", "  ");
            else
			    printf("%c ", (*map)[y][x]);
            x++;
        }
        printf("\n");
		y++;
	}
    printf("\n");
}

static void algo(int y, int x, struct s_map *data)
{
    if (data->map_2d_algo[y][x] == '1' || data->map_2d_algo[y][x] == 'X')
        return;
    if (data->map_2d_algo[y][x] == 'P')
        data->found_p++;
    else if (data->map_2d_algo[y][x] == 'C')
        data->found_c++;
    else if (data->map_2d_algo[y][x] == 'E')
        data->found_e++;
    data->map_2d_algo[y][x] = 'X';
    algo(y+1, x, data);
    algo(y-1, x, data);
    algo(y, x+1, data);
    algo(y, x-1, data);
}

int allocate_2d(struct s_map *data, int i)
{
    data->map_2d_algo = (char **)malloc((data->h + 1) * sizeof(char *));
    data->map_2d_real = (char **)malloc((data->h + 1) * sizeof(char *));
    
    while (i < data->h)
        data->map_2d_algo[i++] = (char *)malloc((data->w + 1) * sizeof(char ));

    i = 0;
    while (i < data->h)
        data->map_2d_real[i++] = (char *)malloc((data->w + 1) * sizeof(char ));

    fill_map(data, &data->map_2d_algo,0,0);
    fill_map(data, &data->map_2d_real,0,0);
    return (0);
}

int initmap(struct s_map *data)
{
    
    if (is_valid(data))
        return (1);

    if (allocate_2d(data, 0))
        return (1);
    
    if (border_check(data, 0))
        return (1);
    
    algo(data->py, data->px, data);
    free(data->map_2d_algo);
    
    if ((data->found_p != data->p) || (data->found_c != data->c) || (data->found_e != data->e))
        return (1);

    print_map(data, &data->map_2d_real,0,0);
        
    return (0);
}
