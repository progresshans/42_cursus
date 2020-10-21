/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:19:50 by hhan              #+#    #+#             */
/*   Updated: 2020/04/30 16:27:52 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	plz_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
}

int		count_split(char const *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

int		plz_split(char const *s, char c, int split_count, char **m)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (s[j] && count < split_count)
	{
		i = 0;
		if (s[j] != c && s[j])
		{
			while (s[i + j] != c && s[i + j])
				i++;
			if (!(m[count] = malloc(sizeof(char) * (i + 1))))
				return (count);
			plz_strlcpy(m[count], &s[j], i);
			count++;
			if (count == split_count)
				break ;
			j += i;
		}
		j++;
	}
	m[count] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		split_count;
	char	**m;

	split_count = count_split(s, c);
	if (!(m = malloc(sizeof(char *) * (split_count + 1))))
		return (NULL);
	if ((split_count = plz_split(s, c, split_count, m)))
	{
		i = 0;
		while (i <= split_count)
			free(m[i++]);
		free(m);
		return (NULL);
	}
	return (m);
}
