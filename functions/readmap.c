
#include "../so_long.h"

int scanline(char *line, struct map *map_data)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] == 'E')
            map_data->e++;
        else if (line[i] == 'P')
            map_data->p++;
        else if (line[i] == 'C')
            map_data->c++;
        i++;
    }
    return (i);
}

void readmap(char *name, struct map *map_data)
{
    char *buff;
    int old_w;
    int fd;

    fd = 0;
    old_w = 0;

    (1) && (map_data->h = 0, map_data->w = 0, map_data->p = 0, map_data->c = 0, map_data->e = 0, map_data->map = NULL);
    
    fd = open(name, O_RDONLY);
    if (fd < 0)
        return ;
    while (1)
    {
        buff = get_next_line(fd);
        if (!buff)
            break;
        map_data->h++;
        map_data->map = ft_strjoin(map_data->map, buff);
        map_data->w = scanline(buff, map_data);
        if ((old_w != map_data->w && old_w != 0))
            break;
        old_w = map_data->w;
    }
    close(fd);
}
