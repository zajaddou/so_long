/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 16:23:36 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int detect_key(int keycode, int *y, int *x)
{
	if (keycode == 123 || keycode == 0)
		(*x)--;
	else if (keycode == 124 || keycode == 2)
		(*x)++;
	else if (keycode == 125 || keycode == 1)
		(*y)++;
	else if (keycode == 126 || keycode == 13)
		(*y)--;
	else
		return (1);
	return (0);
}

static int	move_to(int keycode, t_data *data, int y, int x)
{
	if (detect_key(keycode, &y, &x))
		return (1);
	if (data->map_2d_new[y][x] == '1')
		return (1);
	if (data->map_2d_new[y][x] == 'M')
		kill_player(data);
	if (data->map_2d_new[y][x] == 'C')
	{
		data->c--;
		if (data->c == 0)
			set_xmp(data, "./textures/open.xpm", data->door_x, data->door_y);
	}
	else if (data->map_2d_new[y][x] == 'E' && data->c == 0)
		return (write(1, "\n\n > - You Win :) - <  \n\n", 25), exit(0), 1);
	data->map_2d_new[data->py][data->px] = '0';
	if (data->map_2d_new[data->door_y][data->door_x] == '0')
		data->map_2d_new[data->door_y][data->door_x] = 'E';
	data->px = x;
	data->py = y;
	data->map_2d_new[data->py][data->px] = 'P';
	return (0);
}

static int	move_player(t_data *data, int keycode)
{
	static int	moves;
	if (move_to(keycode, data, data->py, data->px))
		return (1);
	monsters(data, keycode);
	fast_render(data, 0, 0);
	number_render(data, ++moves);
	return (0);
}

int	key_handler(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53)
		game_exit(data);
	else
		move_player(data, keycode);
	return (0);
}
