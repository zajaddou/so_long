/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:15:30 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/31 10:44:04 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_map(t_data *data)
{
	data->door_y = 0;
	data->door_x = 0;
	data->fd = 0;
	data->ow = 0;
	data->h = 0;
	data->w = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->fd = 0;
	data->px = 0;
	data->py = 0;
	data->found_p = 0;
	data->found_c = 0;
	data->found_e = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_2d = NULL;
	data->map_2d_new = NULL;
}

void	free2d(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while ((*map)[i] != NULL)
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

void	allocate_2d(t_data *data, char ***map)
{
	int	i;

	if (*map != NULL)
		error(" You have data ( data->map_2d ) !");
	*map = (char **)malloc((data->h + 1) * sizeof(char *));
	if (!*map)
		error(" Failed to allocate ( data->map_2d ) !");
	i = 0;
	while (i < data->h)
	{
		(*map)[i] = (char *)malloc((data->w + 1) * sizeof(char));
		if (!(*map)[i])
		{
			free2d(map);
			return ;
		}
		i++;
	}
	(*map)[data->h] = NULL;
}

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

int	game_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	free(data->map);
	free2d(&data->map_2d);
	free(data);
	exit(0);
}
