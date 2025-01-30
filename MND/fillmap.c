/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:58:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 23:28:50 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	norm(t_data *data, int y, int x)
{
	data->door_x = x;
	data->door_y = y;
}

void	fill_map(t_data *data, char ***map, int i, int y)
{
	int	x;

	while (y < data->h)
	{
		x = 0;
		while (x <= data->w)
		{
			if (data->map[i] == 'P')
			{
				data->px = x;
				data->py = y;
			}
			if (data->map[i] == 'E')
				norm(data, y, x);
			(*map)[y][x] = '\0';
			if (x != data->w)
				(*map)[y][x] = data->map[i];
			x++;
			i++;
		}
		y++;
	}
	(*map)[y] = NULL;
}
