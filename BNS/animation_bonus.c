/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:30:38 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 17:56:00 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	set_frame(t_data *data, char *xmp, int x, int y)
{
	void	*img;
	
	usleep(50000);
	img = mlx_xpm_file_to_image(data->mlx, xmp, &data->w, &data->h);
	mlx_put_image_to_window(data->mlx, data->win, img, 32 * x, 32 * y);
}

int	animation(void *param)
{
	t_data	*data;
	static int frame;
	int	y;
	int	x;
	
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
					set_frame(data, "./textures/coin.xpm", x, y);
				else
					set_frame(data, "./textures/floor.xpm", x, y);
			}
			x++;
		}
		y++;
	}
	frame = !frame;
	return (0);
}
