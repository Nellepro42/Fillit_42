/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:34:20 by ggambino          #+#    #+#             */
/*   Updated: 2015/12/03 07:34:33 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	prepare_board(t_board *board, int amount)
{
	int	i;

	board->size = 0;
	while ((board->size * board->size) < (amount * 4))
		board->size++;
	i = 0;
	while (i < 256)
		board->data[i++] = '.';
}

void	find_smallest_square(t_tetriminos *tetriminos, int amount)
{
	t_board	board;
	int		y;

	prepare_board(&board, amount);
	while (solve(&board, tetriminos, amount) == 0)
		board.size++;
	y = 0;
	while (y < board.size)
	{
		write(1, &(board.data[16 * y]), board.size);
		write(1, "\n", 1);
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_tetriminos	tetriminos_list[26];
	int				amount;
	int				fd;

	if (argc != 2)
	{
		znprint("error");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		znprint("error");
		return (1);
	}
	if ((amount = load_tetriminos_list(tetriminos_list, fd)) == -1)
	{
		znprint("error");
		return (1);
	}
	close(fd);
	find_smallest_square(tetriminos_list, amount);
	return (0);
}
