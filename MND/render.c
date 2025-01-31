/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 10:22:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_xmp(t_data *data, char *xmp, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, xmp, &data->w, &data->h);
	mlx_put_image_to_window(data->mlx, data->win, img, 32 * x, 32 * y);
}

void	set_image(t_data *data, int y, int x, char c)
{
	if (c == '1')
		set_xmp(data, "./textures/wall.xpm", x, y);
	else if (c == '0')
		set_xmp(data, "./textures/floor.xpm", x, y);
	else if (c == 'P')
		set_xmp(data, "./textures/player.xpm", x, y);
	else if (c == 'C')
	{
		set_xmp(data, "./textures/floor.xpm", x, y);
		set_xmp(data, "./textures/coin.xpm", x, y);
	}
	else if (c == 'E')
		set_xmp(data, "./textures/door.xpm", x, y);
}

void	first_render(t_data *data, int y, int x, char c)
{
	y = 0;
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			c = data->map_2d[y][x];
			set_image(data, y, x, c);
			x++;
		}
		y++;
	}
}

void	fast_render(t_data *data, int y, int x)
{
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			if (data->map_2d[y][x] != data->map_2d_new[y][x])
				set_image(data, y, x, data->map_2d_new[y][x]);
			data->map_2d[y][x] = data->map_2d_new[y][x];
			x++;
		}
		y++;
	}
}
