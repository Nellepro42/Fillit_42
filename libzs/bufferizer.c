/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:41:54 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:41:56 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zbuf_addchar(char *buffer, char data, int *byte)
{
	char	*result;
	int		i;

	if ((*byte % ZBUFFSIZE) == 0)
	{
		result = (char*)malloc(sizeof(char) * (*byte + ZBUFFSIZE));
		i = 0;
		while (i < *byte)
		{
			result[i] = buffer[i];
			i++;
		}
		if (buffer != NULL)
			free(buffer);
	}
	else
		result = buffer;
	result[*byte] = data;
	(*byte)++;
	return (result);
}

char	*zbuf_addstr(char *buffer, char *str, int *byte)
{
	while (*str != '\0')
	{
		buffer = zbuf_addchar(buffer, *str, byte);
		str++;
	}
	return (buffer);
}

char	*zbuf_clean(char *buffer)
{
	char	*str;

	str = zstrdup(buffer);
	free(buffer);
	return (str);
}
