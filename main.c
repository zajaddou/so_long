
# include "so_long.h"

# include <stdio.h>

int main()
{
    struct s_map data;

    data.map_path = "assets/map.ber";

    if (initmap(&data))
        printf("\n Invalid Input !\n\n");

    printf("Enjoy :)\n\n");
    return 0;
}
