/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 10:03:09 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int move_to(int keycode, struct s_data *data, int y, int x)
{
    if (keycode == 123) 
        (x)--;
    else if (keycode == 124) 
        (x)++;
    else if (keycode == 125)
        (y)++;
    else if (keycode == 126)
        (y)--;
    if (data->map_2d[y][x] == '1')
        return (1);
    else if (data->map_2d[y][x] == 'C')
        data->c--;
    else if (data->map_2d[y][x] == 'E' && data->c == 0)
        return (write(1, " You Win :) \n",13),exit(0),1);
    data->map_2d[data->py][data->px] = '0';
    if (data->map_2d[data->door_y][data->door_x] == '0')
        data->map_2d[data->door_y][data->door_x] = 'E';
    data->px = x;
    data->py = y;
    data->map_2d[data->py][data->px] = 'P';
    return (0);
}

int move_player(struct s_data *data, int keycode)
{
    static int moves;
    if (move_to(keycode, data, data->py, data->px) == 0)
    {
        printf(" Move : %d\n",++moves);
        mlx_clear_window(data->mlx, data->win); 
    }
    render_game(data, 0, 0);
    return (0);
}

static int	scanline(char *line, struct s_data *data)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'E')
			data->e++;
		else if (line[i] == 'P')
			data->p++;
		else if (line[i] == 'C')
			data->c++;
		i++;
	}
	return (i);
}

int	read_file(struct s_data *data, int fd, char *buff, char *temp)
{
	
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (1);
		
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			return (1);
		data->h++;
		data->w = scanline(buff, data);
		temp = data->map;
		data->map = ft_strjoin(data->map, buff);
		free(buff);
		free(temp);
		buff = NULL;
		if ((data->ow != data->w) && data->ow > 0)
			return (close(fd), free(data->map), data->map = NULL, 1);
		data->ow = data->w;
	}
	return (0);
}

int validpath(char *path)
{
    int len;
    int i;
    int b;
    char *ext;

    ext = ".ber";
    if (!path)
        return (1);
    len = ft_strlen(path);
    if (len < 4)
        return (1);
    i = len - 1;
    b = 3;
    while (b >= 0)
    {
        if (path[i] != ext[b])
            return (1);
        i--;
        b--;
    }
    return (0);
}
