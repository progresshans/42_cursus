/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:55:47 by hhan              #+#    #+#             */
/*   Updated: 2020/05/01 19:21:51 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	nb_max(unsigned int n, int option)
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

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp_n;
	unsigned int	i;
	int				sign;

	sign = (n < 0) ? 1 : 0;
	temp_n = (n < 0) ? n * -1 : n;
	i = nb_max(temp_n, 2);
	if (sign)
		ft_putchar_fd('-', fd);
	while (i > 0)
	{
		ft_putchar_fd((temp_n / i) + '0', fd);
		temp_n %= i;
		i /= 10;
	}
}