/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 18:36:37 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_block(t_data *data, char *xmp, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, xmp, &data->w, &data->h);
	mlx_put_image_to_window(data->mlx, data->win, img, 64 * x, 64 * y);
}

void set_image(t_data *data, int y, int x, char c)
{
	if (c == '1')
		set_block(data, "./textures/wall.xpm", x, y);
	else if (c == '0')
		set_block(data, "./textures/floor.xpm", x, y);
	else if (c == 'P')
		set_block(data, "./textures/player.xpm", x, y);
	else if (c == 'C')
	{
		set_block(data, "./textures/floor.xpm", x, y);
		set_block(data, "./textures/coin.xpm", x, y);
	}
	else if (c == 'E')
		set_block(data, "./textures/door.xpm", x, y);
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

static int	key_handler(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->map);
		free2d(&data->map_2d);
		free(data);
		exit(0);
	}
	else
		move_player(data, keycode);
	return (0);
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
	data->win = mlx_new_window(data->mlx, data->w * 64,
			data->h * 64, "so_long");
	first_render(data, 0, 0, '0');
	mlx_key_hook(data->win, (int (*)())key_handler, data);
}
