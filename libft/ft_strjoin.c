/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 20:26:57 by hhan              #+#    #+#             */
/*   Updated: 2020/04/27 17:00:52 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	int		i;
	int		j;

	if (!(m = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		m[i++] = *s1++;
	j = 0;
	while (*s2)
		m[i + j++] = *s2++;
	m[i + j] = '\0';
	return (m);
}
