/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:17:51 by hhan              #+#    #+#             */
/*   Updated: 2020/08/03 19:17:53 by hhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	int			i;
	char		b[BUFFER_SIZE + 1];
	static char	*s[OM + 2];

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL || (i = 1) == 0)
		return (-1);
	while (((s[OM + 1] = ft_strchr(s[fd], '\n')) == NULL) && i != 0)
	{
		if ((i = read(fd, b, BUFFER_SIZE)) == -1)
			return (-1);
		b[i] = '\0';
		s[OM + 0] = s[fd] == NULL ? ft_strdup(b) : ft_strjoin(s[fd], b);
		if (s[fd] != NULL)
			free(s[fd]);
		s[fd] = s[OM + 0];
	}
	if (s[OM + 1] != NULL && (s[OM + 0] = s[fd]))
	{
		*line = ft_substr(s[fd], 0, s[OM + 1] - s[fd]);
		s[fd] = ft_strdup(s[OM + 1] + 1);
		free(s[OM + 0]);
		return (1);
	}
	*line = s[fd];
	return ((int)(s[fd] = NULL));
}
