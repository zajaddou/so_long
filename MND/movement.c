/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:56 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 05:56:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int detect_key(int keycode, int *y, int *x)
{
    if (keycode == 123) 
        (*x)--;
    else if (keycode == 124) 
        (*x)++;
    else if (keycode == 125)
        (*y)++;
    else if (keycode == 126)
        (*y)--;
    return (0);
}

static int detect_block(int *y, int *x, struct s_data *data)
{
    if (data->map_2d[*y][*x] == '1')
        return (1);
    if (data->map_2d[*y][*x] == 'C')
        data->c--;
    else if (data->map_2d[*y][*x] == 'E' && data->c == 0)
        exit(0);
    return (0);
}

static int move_to(int keycode, struct s_data *data, int y, int x)
{
    detect_key(keycode, &y, &x);
    
    if (detect_block(&y, &x, data))
        return (1);
 
    data->map_2d[data->py][data->px] = '0';

    if (data->map_2d[data->door_y][data->door_x] == '0')
        data->map_2d[data->door_y][data->door_x] = 'E';

    data->px = x;
    data->py = y;
    data->map_2d[data->py][data->px] = 'P';
    return (0);
}

int move_player(struct s_data *data, int keycode)
{
    if (!move_to(keycode, data, data->py, data->px))
        mlx_clear_window(data->mlx, data->win);
    render_game(data, 0, 0);
    return (0);
}
