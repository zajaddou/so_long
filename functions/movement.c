/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:56 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:00 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int move_player(struct s_render *render, int keycode)
{
    int new_x = 0;
    int new_y = 0;
    
    if (keycode == 123) {
        new_y = render->py;
        new_x = render->px - 1;
    }
    else if (keycode == 124) {
        new_y = render->py;
        new_x = render->px + 1;
    }
    else if (keycode == 125) {
        new_y = render->py + 1;
        new_x = render->px;
    }
    else if (keycode == 126) {
        new_y = render->py - 1;
        new_x = render->px;
    }

    if (render->map_2d[new_y][new_x] != '0' && render->map_2d[new_y][new_x] != 'C')
        return (1);
        
    render->map_2d[new_y][new_x] = 'P';
    mlx_clear_window(render->mlx, render->win);
    render->map_2d[render->py][render->px] = '0';
    render->px = new_x;
    render->py = new_y;
    render_game(render, 0, 0);
    
    return (0);
}