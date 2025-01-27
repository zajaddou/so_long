#include "so_long.h"
#include <stdio.h>

int main(void)
{
    struct s_map data;
    struct s_render render;

    data.map_path = "maps/map.ber";
    if (joingame(&data, &render))
        printf(" invalid game !");
    return (0);
}
