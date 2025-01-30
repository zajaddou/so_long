
#include "so_long.h"

void f()
{
    system("leaks a.out");
}
int main(void)
{
    atexit(f);

    struct s_data *data;

    data = NULL;
    data = malloc (sizeof(struct s_data));
    init_map(data);
    data->map_path = "maps/dev.ber";
    if (validpath(data->map_path))
        exit(1);
    if (joingame(data))
        exit(1);
    mlx_loop(data->mlx);
    return (0);
}

