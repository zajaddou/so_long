/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/28 01:25:00 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int key_handler(int keycode, struct s_render *render)
{
    (void)render;
    printf("%d",keycode);
    if (keycode == 53) // ESC key
        exit(0);
    return 0;
}

static void setblock(struct s_render *render, char *xmp, int x, int y)
{
    void *img;
    img = mlx_xpm_file_to_image(render->mlx, xmp, &render->w, &render->h);
    mlx_put_image_to_window(render->mlx, render->win, img, 64*x, 64*y);
}

static void create(struct s_map *data, struct s_render *render)
{
    char c;

    int y = 0;
    while (data->map_2d_real[y])
    {
        int x = 0;
        while (data->map_2d_real[y][x])
        {
            c = data->map_2d_real[y][x];
            if (c == '1')
                setblock(render,"./textures/wall.xpm",x,y);
            else if (c == '0')
                setblock(render,"./textures/floor.xpm",x,y);
            else if (c == 'P')
                setblock(render,"./textures/player.xpm",x,y);
            else if (c == 'C'){
                setblock(render,"./textures/floor.xpm",x,y);
                setblock(render,"./textures/diamond.xpm",x,y);
            }
            else if (c == 'E')
                setblock(render,"./textures/door.xpm",x,y);
            x++;
        }
        y++;
    }
}

int joingame(struct s_map *data, struct s_render *render)
{
    if (initmap(data))
        return (1);

    render->mlx = mlx_init();
    render->win = mlx_new_window(render->mlx, data->w*64, data->h*64, "so_long");
    render->w = data->w;
    render->h = data->h;

    create(data, render);

    mlx_key_hook(render->win, (int (*)())key_handler, &render);
    
    return (0);
}
