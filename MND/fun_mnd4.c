/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mnd4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:26:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/01/30 11:56:08 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void error(char *str)
{
	if (!str) 
		return ; 
	write(2,"\n",1);
	while (*str)
		write(2, str++, 1);
	write(2,"\n\n",2);
    exit (1);
}

