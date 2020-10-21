/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:50:08 by hhan              #+#    #+#             */
/*   Updated: 2020/04/12 18:33:52 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if ((*str == '+') || (*str == '-'))
		sign = (*str++ == '-') ? -1 : 1;
	while (48 <= *str && *str <= 57)
		result = (result * 10) + (int)(*str++ - '0');
	return (result * sign);
}
