/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 00:14:59 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	start_game(t_data *data)
{
	if (read_file(data, 0, NULL, NULL) && !data->map)
		error(" invalid file !");
	allocate_2d(data, &data->map_2d);
	fill_map(data, &data->map_2d, 0, 0);
	border_check(data, 0);
	algo(data->py, data->px, data);
	free2d(&data->map_2d);
	allocate_2d(data, &data->map_2d);
	allocate_2d(data, &data->map_2d_new);
	fill_map(data, &data->map_2d, 0, 0);
	fill_map(data, &data->map_2d_new, 0, 0);
	if (data->found_p != data->p
		|| data->found_c != data->c || data->found_e != data->e)
		error(" invalid road !");
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 32,
			data->h * 32, "so_long");
	first_render(data, 0, 0, '0');
	mlx_key_hook(data->win, (int (*)())key_handler, data);
	mlx_hook(data->win, 17, 0, (int (*)())game_exit, data);
}
