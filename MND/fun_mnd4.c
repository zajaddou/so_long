/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:26:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 18:32:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *str)
{
	if (!str)
		return ;
	write(2, "\n", 1);
	while (*str)
		write(2, str++, 1);
	write(2, "\n\n", 2);
	exit (1);
}

void	border_check(struct s_data *data, int i)
{
	if (!(data->p == 1 && data->c >= 1 && data->e == 1))
		error(" invalid game !");
	while (i < data->h)
		if ((data->map_2d[i][0] != '1') || \
		(data->map_2d[i++][data->w - 1] != '1'))
			error(" invalid border !");
	i = 0;
	while (i < data->w)
		if (data->map_2d[0][i] != '1' || data->map_2d[data->h - 1][i++] != '1')
			error(" invalid border !");
}

void fast_render(t_data *data, int y, int x)
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
