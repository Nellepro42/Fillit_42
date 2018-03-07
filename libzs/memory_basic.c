/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:42:00 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:42:02 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zstralloc(int size)
{
	char	*newstr;

	newstr = (char*)malloc(sizeof(char) * (size + 1));
	return (newstr);
}

char	*zstrdup(char *str)
{
	int		len;
	int		i;
	char	*newstr;

	i = 0;
	len = zstrlen(str);
	newstr = zstralloc(len);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}

void	zstrcpy(char *str1, char *str2)
{
	while ((*str1++ = *str2++))
		;
}

void	zstrcat(char *str1, char *str2)
{
	while (*str1)
		str1++;
	zstrcpy(str1, str2);
}

char	*zstrconcat(char *str1, char *str2)
{
	char	*newstr;

	newstr = zstralloc(zstrlen(str1) + zstrlen(str2));
	zstrcpy(newstr, str1);
	zstrcat(newstr, str2);
	return (newstr);
}
