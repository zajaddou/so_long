/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:07:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 16:22:09 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void kill_player(t_data *data)
{
	write(1, "\n\n > - You Dead :( - <  \n\n", 26);
	game_exit(data);
}

static void move_monster(t_data *data, int y, int x, int key)
{
	int old_x;
	int old_y;

    old_y = y;
	old_x = x;
	detect_key(key, &x, &y);
	if (data->map_2d_new[y][x] == '0')
	{
		data->map_2d_new[old_y][old_x] = '0';
		data->map_2d_new[y][x] = 'M';
	}
	else if (data->map_2d_new[y][x] == 'P')
		kill_player(data);
}

int	monsters(t_data *data, int key)
{
	int y;
	int x;

	y = 0;
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			if (data->map_2d[y][x] == 'M')
				move_monster(data, y, x, key);
			x++;
		}
		y++;
	}
	return (0);
}
