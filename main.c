#include "so_long.h"
#include <stdio.h>

void f()
{
    system("leaks a.out | grep 'leaks for'");
}
int main(void)
{
    atexit(f);
    struct s_map *data;
    struct s_render *render;

    data = NULL;
    render = NULL;

    data = malloc (sizeof(struct s_map));
    render = malloc (sizeof(struct s_render));

    data->map_path = "maps/map.ber";

    joingame(data, render);

    mlx_loop(render->mlx);
    return (0);
}
