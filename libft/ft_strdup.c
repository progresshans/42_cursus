/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:06:42 by hhan              #+#    #+#             */
/*   Updated: 2020/04/12 18:30:26 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (*s1)
		s2[i++] = *s1++;
	s2[i] = *s1;
	return (s2);
}