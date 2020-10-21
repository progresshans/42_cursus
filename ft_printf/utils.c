/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:35 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 20:54:30 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	str_len(char *string, t_tag *tag)
{
	long long	i;

	if (string == NULL || (tag->conv == 's' && tag->dot && !tag->range))
		return (0);
	i = 0;
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}

long long	nbr_info(long long nbr, t_tag *tag)
{
	long long	i;
	long long	temp;
	long long	option;

	if (nbr == 0 && tag->dot && !tag->range && tag->conv != 'p')
	{
		tag->len = 0;
		return (0);
	}
	option = 10;
	if (tag->conv == 'x' || tag->conv == 'X' || tag->conv == 'p')
		option = 16;
	if (nbr < 0)
		tag->neg = 1;
	nbr = (nbr < 0) ? (nbr * -1) : nbr;
	temp = nbr;
	i = 1;
	while ((nbr /= option) > 0)
		i += 1;
	if (tag->conv == 'p')
		i += 2;
	if (tag->conv == 'p' && temp == 0 && tag->dot)
		i -= 1;
	tag->len = i;
	return (temp);
}
