/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 22:46:26 by hhan              #+#    #+#             */
/*   Updated: 2020/05/01 19:38:25 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			j = 0;
			while (i <= len && needle[j])
			{
				if (haystack[i++] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
