/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_advanced.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 22:39:27 by ggambino          #+#    #+#             */
/*   Updated: 2015/10/01 22:39:47 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

void	zremovespace(char *data)
{
	char	*ptr;
	int		space;

	ptr = data;
	space = 0;
	while (*data == ' ')
		data++;
	while (*data != '\0')
	{
		if (*data != ' ')
		{
			if (space == 1)
			{
				space = 0;
				*(ptr++) = ' ';
			}
			*(ptr++) = *data;
		}
		else
			space = 1;
		data++;
	}
	*ptr = '\0';
}

void	zucase(char *data)
{
	while (*data)
	{
		if (*data >= 'a' && *data <= 'z')
			*data = *data + 'A' - 'a';
		data++;
	}
}

void	zlcase(char *data)
{
	while (*data)
	{
		if (*data >= 'A' && *data <= 'Z')
			(*data) += 'a' - 'A';
		data++;
	}
}
