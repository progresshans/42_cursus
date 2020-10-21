/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:28:52 by hhan              #+#    #+#             */
/*   Updated: 2020/08/03 19:12:41 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t		count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char		*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (!*str)
			return (0);
		str++;
	}
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (*s1)
		ptr[idx++] = *s1++;
	while (*s2)
		ptr[idx++] = *s2++;
	ptr[idx] = '\0';
	return (ptr);
}

char		*ft_substr(char *str, unsigned start, int len)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (idx < len)
		ptr[idx++] = str[start++];
	ptr[idx] = '\0';
	return (ptr);
}

char		*ft_strdup(char *str)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (0);
	while (*str)
		ptr[idx++] = *str++;
	ptr[idx] = '\0';
	return (ptr);
}
