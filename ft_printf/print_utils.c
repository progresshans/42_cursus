/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:31 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 21:05:17 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, t_tag *tag)
{
	write(1, &c, 1);
	tag->total_len += 1;
}

void	print_string(char *string, int i, t_tag *tag)
{
	while (*string && i)
	{
		write(1, string, 1);
		tag->total_len += 1;
		i -= 1;
		string++;
	}
}

void	print_nbr(long long nbr, t_tag *tag)
{
	long long	temp;
	long long	tmp;
	int			option;
	char		*base;

	if (nbr == 0 && tag->dot && !tag->range && tag->conv != 'p')
		return ;
	option = 10;
	base = NUM;
	if (tag->conv == 'x' || tag->conv == 'X' || tag->conv == 'p')
		option = 16;
	if (tag->conv == 'x' || tag->conv == 'p')
		base = HEX_LOW;
	if ((temp = 1) == 0 || tag->conv == 'X')
		base = HEX_UP;
	tmp = nbr;
	while ((tmp /= option) > 0)
		temp *= option;
	while (temp != 0)
	{
		tmp = nbr / temp;
		put_char(base[tmp], tag);
		nbr -= tmp * temp;
		temp /= option;
	}
}

void	print_space(int i, int option, t_tag *tag)
{
	if (tag->neg == 1 || tag->pos == 1)
		i -= 1;
	while (i > 0 && option == tag->minus)
	{
		write(1, " ", 1);
		i -= 1;
		tag->total_len += 1;
	}
}

void	print_zero(int i, t_tag *tag)
{
	if (tag->zero && !tag->dot && (tag->neg || tag->pos))
		i -= 1;
	while (i > 0)
	{
		write(1, "0", 1);
		tag->total_len += 1;
		i -= 1;
	}
}
