#include "so_long.h"
#include <stdio.h>

int main(void)
{
    struct s_map *data;
    struct s_render *render;

    data = NULL;
    data = malloc (sizeof(struct s_map));
    render = NULL;
    render = malloc (sizeof(struct s_render));

    data->map_path = "maps/map.ber";

    joingame(data, render);

    mlx_loop(render->mlx);
    return (0);
}
