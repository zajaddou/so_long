/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/27 04:51:12 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	initvar(struct s_map *data)
{
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
	data->map = NULL;
	data->map_2d = NULL;
}

static int	scanline(char *line, struct s_map *data)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'E')
			data->e++;
		else if (line[i] == 'P')
			data->p++;
		else if (line[i] == 'C')
			data->c++;
		i++;
	}
	return (i);
}

static int	readfile(struct s_map *data)
{
	char	*buff;
	
	initvar(data);
	
	data->fd = open(data->map_path, O_RDONLY);
	if (data->fd < 0)
		return (1);
	while (1)
	{
		buff = get_next_line(data->fd);
		if (!buff)
			return (1);
		data->h++;
		data->w = scanline(buff, data);
		data->map = ft_strjoin(data->map, buff);
		free(buff);
		buff = NULL;
		if ((data->ow != data->w) && data->ow > 0)
			return (close(data->fd), free(data->map), data->map = NULL, 1);
		data->ow = data->w;
	}
	return (0);
}

int ext(struct s_map *data)
{
	
	return (0);
}

int isvalid(struct s_map *data)
{
    if (readfile(data) == 1 && !data->map)
        return (1);

    if (!(data->p == 1 && data->c >= 1 && data->e == 1))
        return (1);
	
    return (0);
}
