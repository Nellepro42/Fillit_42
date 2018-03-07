/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 02:12:43 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/15 02:12:57 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

int	zstrarraylen(char **data)
{
	int	result;

	result = 0;
	while (data[result] != NULL)
		result++;
	return (result);
}
