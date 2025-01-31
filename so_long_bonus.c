/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:07:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 17:09:50 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	return (0);
}
