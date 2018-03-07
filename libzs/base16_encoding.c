/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16_encoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:56:59 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:57:09 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zencode(char *str)
{
	char	*result;
	int		size;
	int		i;

	size = 0;
	while (str[size++])
		;
	result = (char*)malloc(size * 2 + 1);
	i = 0;
	while (i < size)
	{
		result[i * 2] = 'a' + ((str[i] >> 4) & 15);
		result[(i * 2) + 1] = 'a' + (str[i] & 15);
		i++;
	}
	result[size * 2] = '\0';
	return (result);
}

char	*zdecode(char *str)
{
	char	*result;
	int		size;
	int		i;

	size = 0;
	while (str[size])
		size++;
	result = (char*)malloc(size / 2 + 1);
	i = 0;
	while (i < (size / 2))
	{
		result[i] = (str[i * 2] - 'a') << 4;
		result[i] += (str[(i * 2) + 1] - 'a');
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	zencodefd(int source, int destination)
{
	char	in;
	char	out[2];

	while (read(source, &in, 1) > 0)
	{
		out[0] = 'a' + ((in >> 4) & 15);
		out[1] = 'a' + (in & 15);
		write(destination, out, 2);
	}
}

void	zdecodefd(int source, int destination)
{
	char	in;
	char	out;
	int		bitorder;

	bitorder = 0;
	while (read(source, &in, 1) > 0)
	{
		if (in < 'a' || in > 'p')
			return ;
		if (bitorder == 0)
			out = (in - 'a') << 4;
		else
		{
			out += (in - 'a');
			write(destination, &out, 1);
		}
		bitorder = !bitorder;
	}
}
