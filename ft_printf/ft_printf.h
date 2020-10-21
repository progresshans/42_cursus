/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:33:16 by hhan              #+#    #+#             */
/*   Updated: 2020/09/21 20:53:56 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR		-1
# define NUM		"0123456789"
# define HEX_UP		"0123456789ABCDEF"
# define HEX_LOW	"0123456789abcdef"

typedef struct	s_tag
{
	int	total_len;
	int	conv;
	int	neg;
	int	pos;
	int	zero;
	int	zn;
	int	len;
	int	minus;
	int	width;
	int	dot;
	int	range;
	int	star;
	int	sn;
}				t_tag;

int				ft_printf(const char *kwarg, ...);
void			check_conv(va_list args, char *kwarg, t_tag *tag);
void			init_tag(t_tag *tag);

void			put_char(char c, t_tag *tag);
void			print_string(char *string, int i, t_tag *tag);
void			print_nbr(long long nbr, t_tag *tag);
void			print_space(int i, int option, t_tag *tag);
void			print_zero(int i, t_tag *tag);

long long		str_len(char *string, t_tag *tag);
long long		nbr_info(long long nbr, t_tag *tag);

void			division_conv(va_list args, t_tag *tag);
void			find_conv(char **w, t_tag *tag);
void			find_width(char **kwarg, t_tag *tag);
void			find_range(char **kwarg, t_tag *tag);
void			find_star(va_list args, int option, char **kwarg, t_tag *tag);

void			print_c(va_list args, t_tag *tag);
void			print_s(va_list args, t_tag *tag);
void			print_d(va_list args, t_tag *tag);

#endif
