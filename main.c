
#include "so_long.h"

#include <stdio.h>

int isvalid(char *name)
{
    struct s_map data;

    if (readmap(name, &data) == 1 && !data.map)
        return (printf("\n%s\n\n",  " Invalid Map ! "), 1);

    if (!(data.p == 1 && data.c >= 1 && data.e == 1))
        return (printf("\n%s\n\n",  " Invalid Game ! "), 1);
    
    printf("\n%s", data.map);
    printf("\n\n height = %d | width = %d\n\n P = %d \n C = %d \n E = %d\n\n", data.h, data.w, data.p, data.c, data.e);
    return (0);
}

int main(void)
{
    isvalid("assets/map.ber");
    return (0);
}
