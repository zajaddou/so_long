#include "so_long.h"
#include <stdio.h>

int main(void)
{
    struct s_map *data;
    struct s_render *render;

    data = NULL;
    render = NULL;

    data = malloc (sizeof(struct s_map));
    render = malloc (sizeof(struct s_render));

    init_map(data);

    data->map_path = "maps/dev.ber";

    if (joingame(data, render))
        exit(1);

    mlx_loop(render->mlx);
    return (0);
}
