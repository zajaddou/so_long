/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:07:08 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/02 05:07:16 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	kill_player(t_data *data)
{
	write(1, "\n\n > ~ You Dead ☠ ~ <  \n\n", 27);
	game_exit(data);
}

static void	move_monster(t_data *data, int y, int x)
{
	int	old_x;
	int	old_y;
	
	old_y = y;
	old_x = x;
	if (data->c == 1)
		animation(data);
    if (data->py > y)
        y++;
    if (data->py < y)
        y--;
    if (data->px > x)
        x++;
    if (data->px < x)
        x--;
	if (old_y != y && old_x != x)
		return ;
	if (data->map_2d_new[y][x] == '0')
	{
		data->map_2d_new[old_y][old_x] = '0';
		data->map_2d_new[y][x] = 'M';
	}
	else if (data->map_2d_new[y][x] == 'P')
		kill_player(data);
}

int	monsters(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			if (data->map_2d[y][x] == 'M')
				move_monster(data, y, x);
			x++;
		}
		y++;
	}
	fast_render(data, 0, 0);
	usleep(70000);
	return (0);
}
