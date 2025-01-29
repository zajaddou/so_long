/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:26:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/29 04:12:43 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_render(struct s_render *render)
{
	render->h = 0;
	render->w = 0;
	render->px = 0;
	render->py = 0;
	render->coins = 0;
    render->mlx = NULL;
    render->win = NULL;
	render->map_2d = NULL;
    
    render->mlx = malloc(sizeof(void *));
    if (!render->mlx)
        return (1);

    render->win = malloc(sizeof(void *));
    if (!render->win)
        return (1);
    
    return (0);
}

void	init_map(struct s_map *data)
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

void seg(void)
{
    printf("\n\n\t\t\t >- NO SEG HERE -< \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}