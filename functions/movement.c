/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:56 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/29 04:15:30 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int move_to(int keycode, struct s_render *render)
{
    int x = render->px;
    int y = render->py;

    if (keycode == 123) 
        x--;
    if (keycode == 124) 
        x++;
    if (keycode == 125)
        y++;
    if (keycode == 126)
        y--;
    
    if (render->map_2d[y][x] == '1')
        return (1);
        
    if (render->map_2d[x][x] == 'C')
        render->coins--;
    
    else if (render->map_2d[y][x] == 'E' && render->coins == 0)
        exit (0);

    render->map_2d[render->py][render->px] = '0';
    render->py = y;
    render->px = x;
    return (0);
}

int move_player(struct s_render *render, int keycode)
{
    if (move_to(keycode, render))
        return (1);

    mlx_clear_window(render->mlx, render->win);

    printf("DATA:%c\n",render->map_2d[render->py][render->px]);
    printf("COINS:%d\n\n",render->coins);
    
    render->map_2d[render->py][render->px] = 'P';


    render_game(render, 0, 0);
    
    return (0);
}
