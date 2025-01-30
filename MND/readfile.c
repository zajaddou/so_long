/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:56:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 22:57:02 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	read_file(t_data *data, int fd, char *buff, char *temp)
{
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		error(" File not found !");
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			return (1);
		data->h++;
		data->w = entity_check(buff, data);
		temp = data->map;
		data->map = ft_strjoin(data->map, buff);
		free(buff);
		free(temp);
		buff = NULL;
		if ((data->ow != data->w) && data->ow > 0)
			return (close(fd), free(data->map), data->map = NULL, 1);
		data->ow = data->w;
	}
	return (0);
}
