/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:30:38 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/02 02:57:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animation(void *param)
{
	t_data		*data;
	static int	frame;
	int			y;
	int			x;

	y = 0;
	data = (t_data *)param;
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			if (data->map_2d[y][x] == 'C')
			{
				if (frame)
					set_xmp(data, "./textures/coin.xpm", x, y);
				else
					set_xmp(data, "./textures/floor.xpm", x, y);
			}
			x++;
		}
		y++;
	}
	frame = !frame;
	return (0);
}
