/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:42:08 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:42:09 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zsubstr(char *str, int start, int len)
{
	int		l;
	char	*result;
	int		i;

	l = zstrlen(str);
	if (start < 0)
		return (zsubstr(str, start + l, len));
	if (len < 0)
		len = l - start;
	if (start >= l || len <= 0)
		return (zstrdup(""));
	if (start + len > l)
		len = l;
	result = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		zstrncmp(char *str1, char *str2, int n)
{
	int	difference;

	if (n == 0)
		return (0);
	if (str1 == NULL || str2 == NULL)
		return ((str1 == NULL) - (str2 == NULL));
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (((difference = *str1++ - *str2++)) || --n <= 0)
			return (difference);
	}
	return (*str1 - *str2);
}

int		zstrcmp(char *str1, char *str2)
{
	int	difference;

	if (str1 == NULL || str2 == NULL)
		return ((str1 == NULL) - (str2 == NULL));
	while (*str1 != '\0' && *str2 != '\0')
	{
		if ((difference = *str1++ - *str2++))
			return (difference);
	}
	return (*str1 - *str2);
}

int		zstrnpos(char *str, char *sub, int offset)
{
	int	sizemain;
	int	sizesub;
	int pos;

	sizemain = zstrlen(str);
	sizesub = zstrlen(sub);
	if (offset > 0)
	{
		pos = offset;
		str += pos;
	}
	else
		pos = 0;
	while (sizesub + pos <= sizemain)
	{
		if (zstrncmp(str, sub, sizesub) == 0)
			return (pos);
		str++;
		pos++;
	}
	return (-1);
}

int		zstrpos(char *str, char *sub)
{
	return (zstrnpos(str, sub, 0));
}
