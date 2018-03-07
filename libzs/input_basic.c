/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 23:53:46 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/14 23:54:03 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zfilegetcontents(int fd, int *eof)
{
	char	c;
	int		r;
	int		byte;
	char	*result;

	r = 1;
	byte = 0;
	result = NULL;
	while (((r = read(fd, &c, 1) == 1)))
		result = zbuf_addchar(result, c, &byte);
	*eof = (r == 1) ? 0 : 1;
	result = zbuf_addchar(result, '\0', &byte);
	return (zbuf_clean(result));
}

char	*zreadany(int fd, int *eof, char delimiter)
{
	char	c;
	int		r;
	int		byte;
	char	*result;

	r = 1;
	byte = 0;
	result = NULL;
	while (((r = read(fd, &c, 1) == 1)) && c != delimiter)
		result = zbuf_addchar(result, c, &byte);
	*eof = (r == 1) ? 0 : 1;
	result = zbuf_addchar(result, '\0', &byte);
	return (zbuf_clean(result));
}

char	*zreadstring(int fd, int *eof)
{
	return (zreadany(fd, eof, '\0'));
}

char	*zreadline(int fd, int *eof)
{
	return (zreadany(fd, eof, '\n'));
}
