/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:08:01 by hhan              #+#    #+#             */
/*   Updated: 2020/05/01 18:59:45 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	nbr_max(unsigned int n, int option)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 1;
	if (n < 10)
		return (i);
	while (n >= 10)
	{
		j *= 10;
		i += 1;
		n /= 10;
	}
	if (option == 1)
		return (i);
	else
		return (j);
}

char			*ft_itoa(int n)
{
	unsigned int	temp_n;
	unsigned int	i;
	unsigned int	j;
	int				sign;
	char			*result;

	sign = (n < 0) ? 1 : 0;
	temp_n = (n < 0) ? n * -1 : n;
	i = nbr_max(temp_n, 1);
	if (!(result = (char *)malloc(sizeof(char) * (i + sign + 1))))
		return (NULL);
	i = nbr_max(temp_n, 2);
	j = 0;
	if (sign)
		result[j++] = '-';
	while (i > 0)
	{
		result[j++] = (temp_n / i) + '0';
		temp_n %= i;
		i /= 10;
	}
	result[j] = '\0';
	return (result);
}
