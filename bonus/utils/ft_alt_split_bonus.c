/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:49:10 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:28:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_wordlen(char const *s, char c, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i])
			i++;
	}
	return (i);
}

static char	**ft_freeup(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_alt_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (2 + 1));
	if (!s || !str)
		return (NULL);
	while (s[i] && j < 2)
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, ft_wordlen(&s[i], c, j));
			if (!str[j])
				return (ft_freeup(str, j));
			i += ft_wordlen(&s[i], c, j);
			j++;
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
