/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:09:34 by hhan              #+#    #+#             */
/*   Updated: 2020/05/01 18:55:24 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize || dst == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
		*dst++ = src[i++];
	*dst = '\0';
	return (ft_strlen(src));
}
