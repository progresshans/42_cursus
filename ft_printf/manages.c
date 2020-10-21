/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manages.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:24 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 20:33:25 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	division_conv(va_list args, t_tag *tag)
{
	if (tag->conv == 'c' || tag->conv == '%')
		print_c(args, tag);
	else if (tag->conv == 's')
		print_s(args, tag);
	else if (tag->conv == 'd')
		print_d(args, tag);
	else if (tag->conv == 'u')
		print_d(args, tag);
	else if (tag->conv == 'x')
		print_d(args, tag);
	else if (tag->conv == 'X')
		print_d(args, tag);
	else if (tag->conv == 'p')
		print_d(args, tag);
	else if (tag->conv == 'i')
		print_d(args, tag);
}

void	find_conv(char **w, t_tag *tag)
{
	if (**w == 'c' || **w == 's' || **w == 'p' ||
		**w == 'i' || **w == 'u' || **w == 'x' ||
		**w == 'X' || **w == '%' || **w == 'd')
		tag->conv = (int)**w;
	else
		return ;
	(*w)++;
}

void	find_width(char **kwarg, t_tag *tag)
{
	int	temp;

	if (**kwarg == '+')
	{
		tag->pos = 1;
		(*kwarg)++;
	}
	while (**kwarg == '-' || **kwarg == '0')
	{
		if (**kwarg == '-')
			tag->minus = 1;
		if (**kwarg == '0')
			tag->zero = 1;
		(*kwarg)++;
	}
	if (tag->minus && tag->zero)
		tag->zero = 0;
	while ('0' <= **kwarg && **kwarg <= '9')
	{
		temp = (tag->width * 10) + (int)(**kwarg - '0');
		tag->width = temp;
		(*kwarg)++;
	}
}

void	find_range(char **kwarg, t_tag *tag)
{
	int temp;

	if (**kwarg == '.')
	{
		tag->dot = 1;
		(*kwarg)++;
	}
	while ('0' <= **kwarg && **kwarg <= '9')
	{
		temp = (tag->range * 10) + (int)(**kwarg - '0');
		tag->range = temp;
		(*kwarg)++;
	}
}

void	find_star(va_list args, int option, char **kwarg, t_tag *tag)
{
	int	temp;

	if (**kwarg == '*' && option == 1)
	{
		tag->star = 1;
		tag->sn = va_arg(args, int);
		temp = tag->sn < 0 ? tag->sn * -1 : tag->sn;
		tag->minus = tag->sn < 0 ? 1 : tag->minus;
		tag->zero = tag->sn < 0 && tag->zero ? 0 : tag->zero;
		tag->width = tag->star ? temp : tag->width;
		(*kwarg)++;
	}
	if (**kwarg == '*' && option == 2)
	{
		tag->sn = va_arg(args, int);
		tag->range = tag->sn < 0 ? 0 : tag->sn;
		tag->dot = tag->sn < 0 ? 0 : tag->dot;
		(*kwarg)++;
	}
}
