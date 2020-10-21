/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:20:05 by hhan              #+#    #+#             */
/*   Updated: 2020/04/30 16:46:38 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i])
		*dst++ = src[i++];
	*dst = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	unsigned int	i;
	char			*m;

	s_len = 0;
	i = 0;
	while (s[i])
	{
		if (i == start)
			break ;
		i++;
	}
	s_len = ft_strlen(&s[i]) < len ? ft_strlen(&s[i]) : len;
	if(!(m = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	spl_strlcpy(m, &s[i], (s_len + 1));
	return (m);
}
