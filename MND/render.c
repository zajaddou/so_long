/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 04:56:12 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void setblock(struct s_render *render, char *xmp, int x, int y)
{
    void *img;
    
    img = mlx_xpm_file_to_image(render->mlx, xmp, &render->w, &render->h);
    mlx_put_image_to_window(render->mlx, render->win, img, 64*x, 64*y);
}

void render_game(struct s_render *render, int y, int x)
{
    char c;

    y = 0;
    while (render->map_2d[y])
    {
        x = 0;
        while (render->map_2d[y][x])
        {
            c = render->map_2d[y][x];
            if (c == '1')
                setblock(render, "./textures/wall.xpm", x, y);
            else if (c == '0')
                setblock(render, "./textures/floor.xpm", x, y);
            else if (c == 'P')
                setblock(render, "./textures/player.xpm", x, y);
            else if (c == 'C'){
                setblock(render, "./textures/floor.xpm", x, y);
                setblock(render, "./textures/coin.xpm", x, y);
            }
            else if (c == 'E')
                setblock(render,"./textures/door.xpm", x, y);
            x++;
        }
        y++;
    }
}

static int key_handler(int keycode, struct s_render *render)
{
    (void)render;
    if (keycode == 53)
        exit(0);  // ESC key
    else
        move_player(render, keycode);
    return 0;
}

void swap_data(struct s_map *data,struct s_render *render)
{
    render->mlx = mlx_init();
    render->win = mlx_new_window(render->mlx, data->w*64, data->h*64, "so_long");
    render->w = data->w;
    render->h = data->h;
    render->px = data->px;
	render->py = data->py;
	render->coins = data->found_c;
    render->map_2d = data->map_2d;
    render->door_y = data->door_y;
    render->door_x = data->door_x;
}

int joingame(struct s_map *data, struct s_render *render)
{

    if (read_file(data, 0) && !data->map)
        invalid_map();
    
    allocate_2d(data, 0);
    
    border_check(data, 0);

    algo(data->py, data->px, data);
    
    free2D(&data->map_2d);

    allocate_2d(data, 0);
    
    if ((data->found_p != data->p) || (data->found_c != data->c) || (data->found_e != data->e))
        invalid_game();

    if (init_render(render))
        return (1);

    swap_data(data, render);
    
    render_game(render, 0, 0);

    mlx_key_hook(render->win, (int (*)())key_handler, render);
    
    return (0);
}
