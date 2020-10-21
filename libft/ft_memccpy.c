/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 02:32:46 by hhan              #+#    #+#             */
/*   Updated: 2020/04/12 18:33:15 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;

	d = dst;
	while (n--)
	{
		*d++ = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return (d);
	}
	return (0);
}
