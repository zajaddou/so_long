#include "so_long.h"
#include <stdio.h>
#include <mlx.h>


void create(struct s_map *data) {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, data->w*64, data->h*64, "so_long");
    char *paths[] = {"./assets/img/floor.xpm", "./assets/img/wall.xpm", 
                    "./assets/img/coin.xpm", "./assets/img/player.xpm"};
    void *imgs[4];
    int w;
    int h;
    int i = 0;

    while (i < 4)
        imgs[i] = mlx_xpm_file_to_image(mlx, paths[i++], &w, &h);

    int y = 0;
    while (y < data->h)
    {
        int x = 0;
        while (x < data->w) {
            char c = data->map_2d_real[y][x];
            void *img = NULL;
            if (c == '1')
                img = imgs[2];
            else if (c == '0')
                img = imgs[1];
            else if (c == 'C')
                img = imgs[3];
            else if (c == 'P')
                img = imgs[4];
            if (img)
                mlx_put_image_to_window(mlx, win, img, x*64, y*64);
            x++;
        }
        y++;
    }
    
    mlx_loop(mlx);
}

int main(void)
{
    struct s_map data;

    data.map_path = "assets/map.ber";

    if (initmap(&data))
        return (printf(" invalid game !"), 1);

    create(&data);

    return (0);
}
