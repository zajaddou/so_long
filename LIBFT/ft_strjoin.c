/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zakariaajaddou@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:31:49 by zajaddou          #+#    #+#             */
/*   Updated: 2024/11/09 16:56:06 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_strings(char *dest, const char *src1, const char *src2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i++;
	}
	j = 0;
	while (src2[j])
	{
		dest[i] = src2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*all_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	all_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!all_str)
		return (NULL);
	copy_strings(all_str, s1, s2);
	return (all_str);
}
