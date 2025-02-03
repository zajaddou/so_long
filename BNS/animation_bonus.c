/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:30:38 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/03 02:16:28 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animation(t_data	*data, int x, int y)
{
	static int	frame;
	static int	on_off;

	if (frame++ < 2500)
		return (1);
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			if (data->map_2d[y][x] == 'C')
			{
				if (on_off)
					set_xmp(data, "./textures/coin.xpm", x, y);
				else
					set_xmp(data, "./textures/floor.xpm", x, y);
			}
			x++;
		}
		y++;
	}
	frame = 0;
	on_off = !on_off;
	return (0);
}

int	loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->c == 1)
		animation(data, 0, 0);
	monsters(data, 0, 0);
	return (0);
}
