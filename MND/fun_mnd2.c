/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:47 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	move_to(int keycode, t_data *data, int y, int x)
{
	if (keycode == 123 || keycode == 0)
		(x)--;
	else if (keycode == 124 || keycode == 2)
		(x)++;
	else if (keycode == 125 || keycode == 1)
		(y)++;
	else if (keycode == 126 || keycode == 13)
		(y)--;
	if (data->map_2d[y][x] == '1')
		return (1);
	else if (data->map_2d[y][x] == 'C')
	{
		data->c--;
		if (data->c == 0)
			data->open = 1;
	}
	else if (data->map_2d[y][x] == 'E' && data->c == 0)
		return (write(1, "\n\n > - You Win :) - <  \n\n", 25), exit(0), 1);
	data->map_2d[data->py][data->px] = '0';
	if (data->map_2d[data->door_y][data->door_x] == '0')
		data->map_2d[data->door_y][data->door_x] = 'E';
	data->px = x;
	data->py = y;
	data->map_2d[data->py][data->px] = 'P';
	return (0);
}

int	move_player(t_data *data, int keycode)
{
	static int	moves;

	if (move_to(keycode, data, data->py, data->px))
		return (1);
	write(1, " Move : ", 9);
	ft_putnbr_fd(++moves, 1);
	write(1, "\n", 1);
	mlx_clear_window(data->mlx, data->win);
	render_game(data, 0, 0, '0');
	return (0);
}

static int	scan_line(char *line, t_data *data)
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
		else if (line[i] != '0' && line[i] != '1')
			error(" invalid entity !");
		i++;
	}
	return (i);
}

int	read_file(t_data *data, int fd, char *buff, char *temp)
{
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		error(" File not found !");
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			return (1);
		data->h++;
		data->w = scan_line(buff, data);
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

int	valid_path(char *path, int len, int i, int e)
{
	char	*ext;

	ext = ".ber";
	if (!path)
		error(" invalid file !");
	len = ft_strlen(path);
	if (len < 4)
		error(" invalid file !");
	i = len - 1;
	e = 3;
	while (e >= 0)
		if (path[i--] != ext[e--])
			return (1);
	return (0);
}
