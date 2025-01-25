
#include "so_long.h"

#include <stdio.h>

int main(void)
{
    struct map data;
    
    readmap("assets/map.ber", &data);

    printf("\n%s",data.map);

    printf("\n\n height = %d | width = %d\n\n P = %d \n C = %d \n E = %d\n\n", data.h, data.w, data.p, data.c, data.e);
}
