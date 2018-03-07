/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:14:17 by ggambino          #+#    #+#             */
/*   Updated: 2015/12/03 07:52:40 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libzs/libzs.h"

typedef struct	s_tetriminos {
	char		id;
	int			valid;
	int			x;
	int			y;
	int			width;
	int			height;
	char		data[16];
}				t_tetriminos;

typedef struct	s_board
{
	int			size;
	int			current;
	char		data[256];
}				t_board;

void			shift_tetriminos_data(char *str, int repeat);
int				verify_tetriminos_data(char *str);
void			optimize_tetriminos(t_tetriminos *tetriminos);

int				tetriminos_input_ok(char *in);
t_tetriminos	read_tetriminos(int fd, int *eof);
int				get_tetriminos(t_tetriminos *tetriminos, int fd, int *eof);
int				load_tetriminos_list(t_tetriminos *tetriminos, int fd);

int				tetriminos_fit(t_board *board, t_tetriminos *tetriminos);
void			tetriminos_write(t_board *board, t_tetriminos *tetriminos,
					char c);
int				find_position(t_board *board, t_tetriminos *tetriminos);
int				solve(t_board *board, t_tetriminos *tetriminos, int amount);

void			prepare_board(t_board *board, int amount);
void			find_smallest_square(t_tetriminos *tetriminos, int amount);

#endif
