/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:31 by zajaddou          #+#    #+#             */
/*   Updated: 2025/02/02 07:03:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		error(" invalid input !");
	data = malloc (sizeof(t_data));
	if (!data)
		error(" Failed to allocate ( data ) !");
	data->map_path = av[1];
	init_map(data);
	if (path_check(data->map_path, 0, 0, 0))
		error(" invalid file name !");
	start_game(data);
	mlx_loop(data->mlx);
	return (0);
}
