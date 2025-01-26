
# include "so_long.h"

# include <stdio.h>

int main()
{
    struct s_map data;

    data.map_path = "assets/map.ber";

    initmap(&data);

    return 0;
}
