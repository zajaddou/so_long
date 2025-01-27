/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 14:44:08 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int key_handler(int keycode, struct s_render *render)
{
    printf("%d",render->px);
    if (keycode == 53) // ESC key
        exit(0);
    return 0;
}

static void create(struct s_map *data, struct s_render *render)
{
    int i;
    
    i = 0;

    while (i < 4)
    {
        render->imgs[i] = mlx_xpm_file_to_image(render->mlx, render->paths[i], &data->w, &data->h);
    }
    int y = 0;
    while (y < data->h)
    {
        int x = 0;
        while (x < data->w)
        {
            char c = data->map_2d_real[y][x];
            void *img = NULL;
            if (c == '1')
                img = render->imgs[1];
            else if (c == '0')
                img = render->imgs[3];
            else if (c == 'C')
                img = render->imgs[2];
            else if (c == 'P')
                img = render->imgs[0];
            if (img)
                mlx_put_image_to_window(render->mlx, render->win, img, x*64, y*64);
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

    render->paths[0] = "./textures/player.xpm";
    render->paths[1] = "./textures/wall.xpm";
    render->paths[2] = "./textures/coin.xpm";
    render->paths[3] = "./textures/floor.xpm";

    create(data, render);

    mlx_key_hook(render->win, (int (*)())key_handler, &render);
    mlx_loop(render->mlx);
    
    return (0);
}
