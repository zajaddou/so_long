/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:41:40 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 22:57:36 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	algo(int y, int x, t_data *data)
{
	if (data->map_2d[y][x] == '1' || data->map_2d[y][x] == 'X')
		return ;
	if (data->map_2d[y][x] == 'P')
		data->found_p++;
	else if (data->map_2d[y][x] == 'C')
		data->found_c++;
	else if (data->map_2d[y][x] == 'E')
		data->found_e++;
	data->map_2d[y][x] = 'X';
	algo(y + 1, x, data);
	algo(y - 1, x, data);
	algo(y, x + 1, data);
	algo(y, x - 1, data);
}
