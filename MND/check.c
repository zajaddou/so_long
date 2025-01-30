/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:26:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 23:21:59 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	entity_check(char *line, t_data *data)
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
		else if (line[i] != '0' && line[i] != '1')
			error(" invalid entity !");
		i++;
	}
	return (i);
}

int	path_check(char *path, int len, int i, int e)
{
	char	*ext;

	ext = ".ber";
	if (!path)
		error(" invalid file !");
	len = ft_strlen(path);
	if (len < 4)
		error(" invalid file !");
	i = len - 1;
	e = 3;
	while (e >= 0)
		if (path[i--] != ext[e--])
			return (1);
	return (0);
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
