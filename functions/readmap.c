/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:38:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/26 08:06:04 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init(struct s_map *data, int *ow, int *fd)
{
	*fd = 0;
	*ow = 0;
	data->h = 0;
	data->w = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->fd = 0;
	data->map = NULL;
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

static int	readmap(char *name, struct s_map *data)
{
	char	*buff;
	int		ow;

	init(data, &ow, &data->fd);
	data->fd = open(name, O_RDONLY);
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
		if (((ow != data->w) && ow)
			|| ((data->w == data->h) && ((data->h + data->w) > 0)))
			return (close(data->fd), free(data->map), data->map = NULL, 1);
		ow = data->w;
	}
	return (0);
}

int isvalid(char *name, struct s_map *data)
{
    if (readmap(name, data) == 1 && !data->map)
        return (printf("\n%s\n\n",  " Invalid Map ! "), 1);

    if (!(data->p == 1 && data->c >= 1 && data->e == 1))
        return (printf("\n%s\n\n",  " Invalid Game ! "), 1);
    
	int i = 0;

	while (data->map[i])
	{
		if (data->map[i] == '1' )
			printf("%s", "▉");
		else if (data->map[i] == '0')
			printf("%c", ' ');
		else
			printf("%c", data->map[i]);
		i++;
	}
	
    printf("\n\n height = %d | width = %d\n\n P = %d \n C = %d \n E = %d\n\n", data->h, data->w, data->p, data->c, data->e);
    return (0);
}
