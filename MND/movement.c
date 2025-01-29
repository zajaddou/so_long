/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:56 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/29 06:11:19 by zajaddou         ###   ########.fr       */
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

static int detect_block(int *y, int *x, struct s_render *render)
{
    if (render->map_2d[*y][*x] == '1')
        return (1);
    if (render->map_2d[*y][*x] == 'C')
        render->coins--;
    else if (render->map_2d[*y][*x] == 'E' && render->coins == 0)
        exit(0);
    return (0);
}

static int move_to(int keycode, struct s_render *render)
{
    int x = render->px;
    int y = render->py;

    detect_key(keycode, &y, &x);
    
    if (detect_block(&y, &x, render))
        return (1);
 
    render->map_2d[render->py][render->px] = '0';

    if (render->map_2d[render->door_y][render->door_x] == '0')
        render->map_2d[render->door_y][render->door_x] = 'E';

    render->px = x;
    render->py = y;
    render->map_2d[render->py][render->px] = 'P';
    return (0);
}

int move_player(struct s_render *render, int keycode)
{
    
    if (move_to(keycode, render))
        return (1);

    mlx_clear_window(render->mlx, render->win);

    render_game(render, 0, 0);
    
    return (0);
}
