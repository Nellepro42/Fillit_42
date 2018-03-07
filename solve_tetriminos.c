/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:32:21 by ggambino          #+#    #+#             */
/*   Updated: 2015/12/03 07:32:30 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetriminos_fit(t_board *board, t_tetriminos *tetriminos)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = 0;
	py = tetriminos->y;
	while (y < tetriminos->height)
	{
		x = 0;
		px = tetriminos->x;
		while (x < tetriminos->width)
		{
			if (tetriminos->data[y * 4 + x] == '#'
				&& board->data[py * 16 + px] != '.')
				return (0);
			x++;
			px++;
		}
		y++;
		py++;
	}
	return (1);
}

void	tetriminos_write(t_board *board, t_tetriminos *tetriminos, char c)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = 0;
	py = tetriminos->y;
	while (y < tetriminos->height)
	{
		x = 0;
		px = tetriminos->x;
		while (x < tetriminos->width)
		{
			if (tetriminos->data[y * 4 + x] == '#')
				board->data[py * 16 + px] = c;
			x++;
			px++;
		}
		y++;
		py++;
	}
}

int		find_position(t_board *board, t_tetriminos *tetriminos)
{
	while (1)
	{
		tetriminos->x++;
		if (tetriminos->x + tetriminos->width > board->size)
		{
			tetriminos->x = 0;
			tetriminos->y++;
		}
		if (tetriminos->x + tetriminos->width > board->size)
			return (0);
		if (tetriminos->y + tetriminos->height > board->size)
			return (0);
		if (tetriminos_fit(board, tetriminos))
			return (1);
	}
	return (0);
}

int		solve(t_board *board, t_tetriminos *tetriminos, int amount)
{
	if (amount == 0)
		return (1);
	else
	{
		tetriminos->x = -1;
		tetriminos->y = 0;
		while (find_position(board, tetriminos))
		{
			tetriminos_write(board, tetriminos, tetriminos->id);
			if (solve(board, tetriminos + 1, amount - 1))
				return (1);
			tetriminos_write(board, tetriminos, '.');
		}
	}
	return (0);
}
