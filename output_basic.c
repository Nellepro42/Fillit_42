/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:42:25 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:42:28 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

int		zstrlen(char *str)
{
	int	zlen;

	zlen = 0;
	while (str[zlen] != '\0')
		zlen++;
	return (zlen);
}

void	zputchar(char c)
{
	write(1, &c, 1);
}

void	zputstr(char *str)
{
	write(1, str, zstrlen(str));
}

void	zputnbr(int nbr)
{
	char c;

	if (nbr > 9 || nbr < -9)
		zputnbr(nbr / 10);
	else if (nbr < 0)
		write(1, "-", 1);
	nbr = (nbr < 0) ? -(nbr % 10) : (nbr % 10);
	c = '0' + nbr;
	zputchar(c);
}

void	znprint(char *str)
{
	zputstr(str);
	zputchar('\n');
}
