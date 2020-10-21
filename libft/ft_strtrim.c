/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:16:01 by hhan              #+#    #+#             */
/*   Updated: 2020/05/01 18:43:10 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_set(char target, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == target)
			return (1);
		i++;
	}
	return (0);
}

void	trim_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i])
		*dst++ = src[i++];
	*dst = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	int		start;
	int		end;
	int		len;

	if (s1 == 0 || set == 0)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (start <= end && is_set(s1[start], set))
		start++;
	while (0 <= end && is_set(s1[end], set))
		end--;
	len = end > start ? end - start + 1 : 0;
	if(!(m = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	trim_strlcpy(m, &s1[start], len + 1);
	return (m);
}
