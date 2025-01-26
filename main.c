
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
        while (x < w+1)
        {
            if (x == w)
                (*map_2d)[y][x] = '\0';
            else
                (*map_2d)[y][x] = map[i];
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

    int i;
    int y;
    int x;

    x = 0;
    i = 0;
    y = 0;

    char **map_2d;
    
    map_2d = (char **)malloc((data.h + 1) * sizeof(char *));

    while (i < data.h)
        map_2d[i++] = (char *)malloc((data.w + 1) * sizeof(char ));

    m2d(data.map, data.w, data.h, &map_2d);

    y = 0;
    while (y < data.h)
    {
        if (!(map_2d[y][0] == '1' && map_2d[y][data.w-1] == '1'))
            return (printf("\n%s\n\n",  " Invalid Map ! "), 1);
        y++;
    }

    

    return 0;
}
