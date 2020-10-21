/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:27 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 20:57:09 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list args, t_tag *tag)
{
	char	c;
	int		temp;

	if (tag->conv == 'c')
		c = va_arg(args, int);
	else
		c = '%';
	tag->len = 1;
	tag->zn = tag->zero ? tag->width - tag->len : 0;
	tag->len += (tag->zn < 0) ? 0 : tag->zn;
	temp = tag->width - tag->len;
	tag->width = (temp > 0) ? temp : 0;
	print_space(tag->width, 0, tag);
	print_zero(tag->zn, tag);
	put_char(c, tag);
	print_space(tag->width, 1, tag);
}

void	print_s(va_list args, t_tag *tag)
{
	char	*s;
	int		temp;

	s = va_arg(args, char *);
	s = (s == NULL) ? "(null)" : s;
	tag->len = tag->dot ? tag->range : str_len(s, tag);
	tag->len = (tag->len > str_len(s, tag)) ? str_len(s, tag) : tag->len;
	tag->zn = tag->zero ? tag->width - tag->len : 0;
	tag->len += (tag->zn < 0) ? 0 : tag->zn;
	temp = tag->width - tag->len;
	tag->width = (temp > 0) ? temp : 0;
	print_space(tag->width, 0, tag);
	print_zero(tag->zn, tag);
	print_string(s, tag->len, tag);
	print_space(tag->width, 1, tag);
}

void	print_d(va_list args, t_tag *tag)
{
	long long	d;
	long long	temp;

	if (tag->conv == 'd' || tag->conv == 'i')
		d = nbr_info(va_arg(args, int), tag);
	else if (tag->conv == 'u' || tag->conv == 'x' || tag->conv == 'X')
		d = (unsigned int)nbr_info(va_arg(args, unsigned int), tag);
	else
		d = nbr_info(va_arg(args, long long), tag);
	tag->zn = tag->zero ? tag->width - tag->len : 0;
	tag->zn = tag->dot ? tag->range - tag->len : tag->zn;
	tag->len += (tag->zn < 0) ? 0 : tag->zn;
	temp = tag->width - tag->len;
	tag->width = (temp > 0) ? temp : 0;
	print_space(tag->width, 0, tag);
	if (tag->neg == 1 && tag->conv != 'u')
		put_char('-', tag);
	else if (tag->pos == 1 && tag->conv != 'u')
		put_char('+', tag);
	print_zero(tag->zn, tag);
	tag->conv == 'p' ? print_string("0x", 2, tag) : 0;
	if (!(tag->conv == 'p' && d == 0 && tag->dot))
		print_nbr(d, tag);
	print_space(tag->width, 1, tag);
}
