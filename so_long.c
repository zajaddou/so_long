/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:31 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 22:45:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	data = malloc (sizeof(t_data));
	init_map(data);
	data->map_path = "maps/dev.ber";
	if (path_check(data->map_path, 0, 0, 0))
		error(" invalid file name !");
	start_game(data);
	mlx_loop(data->mlx);
	return (0);
}
