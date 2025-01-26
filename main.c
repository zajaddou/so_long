
#include "so_long.h"

#include <stdio.h>

int main()
{
    struct s_map data;

    data.map_path = "assets/map.ber";

    initmap(&data);


    // Now Time For Algoo , algo time Ohhhhh
    printf("%s\n\n", data.map);

    return 0;
}
