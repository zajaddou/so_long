/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:20:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 16:23:38 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	setblock(t_data *data, char *xmp, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, xmp, &data->w, &data->h);
	mlx_put_image_to_window(data->mlx, data->win, img, 64 * x, 64 * y);
}

void	is_open(t_data *data, int y, int x)
{
	if (data->open)
		setblock(data, "./textures/door_open.xpm", x, y);
	else
		setblock(data, "./textures/door.xpm", x, y);
}

void	render_game(t_data *data, int y, int x, char c)
{
	y = 0;
	while (data->map_2d[y])
	{
		x = 0;
		while (data->map_2d[y][x])
		{
			c = data->map_2d[y][x];
			if (c == '1')
				setblock(data, "./textures/wall.xpm", x, y);
			else if (c == '0')
				setblock(data, "./textures/floor.xpm", x, y);
			else if (c == 'P')
				setblock(data, "./textures/player.xpm", x, y);
			else if (c == 'C')
			{
				setblock(data, "./textures/floor.xpm", x, y);
				setblock(data, "./textures/coin.xpm", x, y);
			}
			else if (c == 'E')
				is_open(data, y, x);
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
	allocate_2d(data, 0);
	border_check(data, 0);
	algo(data->py, data->px, data);
	free2d(&data->map_2d);
	allocate_2d(data, 0);
	if (data->found_p != data->p
		|| data->found_c != data->c || data->found_e != data->e)
		error(" invalid road !");
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 64,
			data->h * 64, "so_long");
	render_game(data, 0, 0, '0');
	mlx_key_hook(data->win, (int (*)())key_handler, data);
}
