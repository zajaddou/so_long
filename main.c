
#include "so_long.h"

#include <stdio.h>

static void m2d(char *map, int w, int h, char ***map_2d)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (y < h)
    {
        x = 0;
        printf("%d : ",y);
        while (x < w+1)
        {
            usleep(2000);
            if (x == w)
            {
                (*map_2d)[y][x] = '\0';
                printf(" *\n");
            }
            else {
                printf("▅");
                (*map_2d)[y][x] = map[i];
            }
            i++;
            x++;
        }
        y++;
    }
    (*map_2d)[y] = NULL;
}

int main()
{
    struct s_map data;

    isvalid("assets/map.ber", &data);

    int i  = 0;
    int y  = 0;
    int x  = 0;

    char **map_2d;
    
    map_2d = (char **)malloc((data.h + 1) * sizeof(char *));

    while (i < data.h)
        map_2d[i++] = (char *)malloc((data.w + 1) * sizeof(char ));

    printf("> Convirt Map to 2D Arrey : \n\n");
    m2d(data.map, data.w, data.h, &map_2d);
    printf("\n\n");

    printf("%s",map_2d[7]);

    return 0;
}
