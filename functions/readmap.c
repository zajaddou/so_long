/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/29 02:45:47 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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

static int	readfile(struct s_map *data, int fd)
{
	char	*buff;
	
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (1);
		
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			return (1);
		data->h++;
		data->w = scanline(buff, data);
		data->map = ft_strjoin(data->map, buff);
		free(buff);
		buff = NULL;
		if ((data->ow != data->w) && data->ow > 0)
			return (close(fd), free(data->map), data->map = NULL, 1);
		data->ow = data->w;
	}
	if (!(data->p == 1 && data->c >= 1 && data->e == 1))
        return (1);
	return (0);
}

static int validpath(char *path)
{
    size_t len;
    size_t i;
    char *ext;

    ext = ".ber";
    if (!path)
        return (1);
    
    len = ft_strlen(path);
    if (len < 4)
        return (1);
    
    i = len - 1;
    for (int j = 3; j >= 0; j--)
    {
        if (path[i] != ext[j])
            return (1);
        i--;
    }
    return (0);
}

int is_valid(struct s_map *data)
{
	if (validpath(data->map_path) == 1)
        return (1);
		
    if ((readfile(data, 0) == 1) && (data->map == NULL))
        return (1);

    return (0);
}
