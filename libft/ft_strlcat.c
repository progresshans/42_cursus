/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:13:50 by hhan              #+#    #+#             */
/*   Updated: 2020/04/12 18:33:57 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total_size;
	size_t	copy_size;
	int		flag;

	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	total_size = ft_strlen(dst) + ft_strlen(src);
	copy_size = dstsize - ft_strlen(dst) - 1;
	flag = copy_size ? 1 : 0;
	while (*dst)
		dst++;
	while (*src && copy_size--)
		*dst++ = *src++;
	if (flag)
		*dst = '\0';
	return (total_size);
}
