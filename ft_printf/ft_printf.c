/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:10 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 20:45:57 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *kwarg, ...)
{
	va_list	args;
	t_tag	*tag;
	int		total_len;

	if (!(tag = malloc(sizeof(t_tag))))
		return (ERROR);
	tag->total_len = 0;
	va_start(args, kwarg);
	check_conv(args, (char *)kwarg, tag);
	total_len = tag->total_len;
	free(tag);
	va_end(args);
	return (total_len);
}

void	check_conv(va_list args, char *kwarg, t_tag *tag)
{
	while (*kwarg)
	{
		if (*kwarg == '%')
		{
			kwarg++;
			init_tag(tag);
			find_width(&kwarg, tag);
			find_star(args, 1, &kwarg, tag);
			find_range(&kwarg, tag);
			find_star(args, 2, &kwarg, tag);
			find_conv(&kwarg, tag);
			division_conv(args, tag);
		}
		else
		{
			put_char(*kwarg, tag);
			kwarg++;
		}
	}
}

void	init_tag(t_tag *tag)
{
	tag->conv = 0;
	tag->neg = 0;
	tag->pos = 0;
	tag->len = 0;
	tag->zero = 0;
	tag->zn = 0;
	tag->minus = 0;
	tag->width = 0;
	tag->dot = 0;
	tag->range = 0;
	tag->star = 0;
	tag->sn = 0;
}
