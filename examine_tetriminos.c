/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:26:17 by ggambino          #+#    #+#             */
/*   Updated: 2015/12/03 07:26:26 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_tetriminos_data(char *str, int repeat)
{
	int	i;

	while (repeat)
	{
		i = 0;
		while (i < 15)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = ' ';
		repeat--;
	}
}

int		verify_tetriminos_data(char *str)
{
	int			id;
	int			i;
	static int	accepted[] = {51, 99, 306, 54, 561, 15, 4369, 275, 113, 802,
								71, 23, 785, 116, 547, 39, 305, 114, 562};

	id = 0;
	i = 0;
	while (i < 16)
	{
		if (str[i] == '#')
			id += (1 << i);
		i++;
	}
	i = 0;
	while (i < 19)
	{
		if (id == accepted[i])
			return (1);
		i++;
	}
	return (0);
}

void	optimize_tetriminos(t_tetriminos *tetriminos)
{
	char	*dat;
	int		i;
	int		j;

	dat = tetriminos->data;
	j = 8;
	while (dat[0] != '#' && dat[1] != '#' && dat[2] != '#' && dat[3] != '#'
		&& j-- > 0)
		shift_tetriminos_data(dat, 4);
	while (dat[0] != '#' && dat[4] != '#' && dat[8] != '#' && dat[12] != '#'
		&& j-- > 0)
		shift_tetriminos_data(dat, 1);
	i = 0;
	while (i < 4)
	{
		if (dat[i] == '#' || dat[i + 4] == '#' || dat[i + 8] == '#')
			tetriminos->width = i + 1;
		if (dat[i * 4] == '#' || dat[i * 4 + 1] == '#'
			|| dat[i * 4 + 2] == '#')
			tetriminos->height = i + 1;
		i++;
	}
}
