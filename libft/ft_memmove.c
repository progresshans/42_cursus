/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 01:49:33 by hhan              #+#    #+#             */
/*   Updated: 2020/04/30 18:59:25 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	unsigned char	tempchr[len];

	if (dst == 0 && src == 0)
		return (NULL);
	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	ft_memcpy(tempchr, srcptr, len);
	ft_memcpy(dstptr, tempchr, len);
	return (dst);
}
