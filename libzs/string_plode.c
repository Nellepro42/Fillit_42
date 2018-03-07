/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_plode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:42:36 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:42:37 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

char	*zimplode(char *delimiter, char **list)
{
	int		strsize;
	int		arraysize;
	int		i;
	char	*result;

	arraysize = 0;
	strsize = 0;
	if (list == NULL)
		return (NULL);
	if (delimiter == NULL)
		delimiter = "";
	while (list[arraysize] != NULL)
		strsize += zstrlen(list[arraysize++]);
	if (arraysize < 1)
		return (zstrdup(""));
	i = 1;
	result = zstralloc(strsize + (zstrlen(delimiter) * (arraysize - 1)));
	zstrcpy(result, list[0]);
	while (i < arraysize)
	{
		zstrcat(result, delimiter);
		zstrcat(result, list[i++]);
	}
	return (result);
}

char	**zexplode(char *delimiter, char *str)
{
	int		pos;
	int		nextpos;
	int		i;
	char	**result;

	if (str == NULL || zstrlen(delimiter) < 1)
		return (NULL);
	pos = 0;
	i = 1;
	while (i++ && (nextpos = zstrnpos(str, delimiter, pos)) != -1)
		pos = nextpos + 1;
	pos = 0;
	result = (char**)malloc(sizeof(char*) * i);
	i = 0;
	while ((nextpos = zstrnpos(str, delimiter, pos)) != -1)
	{
		result[i++] = zsubstr(str, pos, nextpos - pos);
		pos = nextpos + zstrlen(delimiter);
	}
	result[i++] = zsubstr(str, pos, -1);
	result[i] = NULL;
	return (result);
}
