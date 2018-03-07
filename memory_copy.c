/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 04:44:04 by ggambino          #+#    #+#             */
/*   Updated: 2015/10/05 04:46:51 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

void	*zmemcpy(void *s1, void *s2, int n)
{
	char	*dest;
	char	*src;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (s1);
	dest = (char*)s1;
	src = (char*)s2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*zmemcpyoffset(void *s1, void *s2, int n, int offset)
{
	return (zmemcpy(((char*)s1) + offset, s2, n));
}
