/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:23:04 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 13:35:13 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
			data->h * 32, "so_long bonus");
	first_render(data, 0, 0, '0');
	mlx_string_put(data->mlx, data->win, 10, 5, 0xFFFFFF, "Moves 0");
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, 0, game_exit, data);
}
