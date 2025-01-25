/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:42:03 by zajaddou          #+#    #+#             */
/*   Updated: 2024/11/18 07:50:18 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **dest, int i)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
	return (0);
}

static void	ft_set(char *dest, const char *str, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[len] = '\0';
}

static char	**split_set(char const *str, char c, char **dest, int c_words)
{
	int	si;
	int	wi;
	int	wl;

	si = 0;
	wi = 0;
	wl = 0;
	while (wi < c_words)
	{
		while (str[si] == c)
			si++;
		while (str[si] != c && str[si] != '\0')
		{
			si++;
			wl++;
		}
		dest[wi] = (char *)malloc((wl + 1) * sizeof(char));
		if (!dest[wi])
			return (free_array(dest, wi));
		ft_set(dest[wi], str, (si - wl), wl);
		wl = 0;
		wi++;
	}
	dest[wi] = NULL;
	return (dest);
}

static size_t	count_word(char const *s, char c)
{
	size_t	c_words;
	size_t	i;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			c_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	c_words;

	c_words = count_word(s, c);
	dest = (char **)malloc((c_words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	return (split_set(s, c, dest, c_words));
}
