
#include "so_long.h"

void leak(){
    system("leaks a.out");
}
int main(int ac, char **av)
{
    //atexit(leak);

    struct s_data *data;

    data = NULL;
    data = malloc (sizeof(struct s_data));

    init_map(data);

    data->map_path = "maps/.ber";
    
    if (valid_path(data->map_path, 0, 0, 0))
        exit(1);
    if (joingame(data))
        exit(1);
    mlx_loop(data->mlx);
    return (0);
}
