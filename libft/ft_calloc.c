/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:43:06 by hhan              #+#    #+#             */
/*   Updated: 2020/10/10 23:24:16 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	ptr_size;

	ptr_size = count * size;
	if (!(ptr = (void *)malloc(ptr_size)))
		return (0);
	ft_memset(ptr, 0, ptr_size);
	return (ptr);
}
