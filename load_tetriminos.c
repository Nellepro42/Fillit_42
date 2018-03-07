/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:29:04 by ggambino          #+#    #+#             */
/*   Updated: 2015/12/03 07:29:22 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				tetriminos_input_ok(char *in)
{
	int	x;

	if (in == NULL || zstrlen(in) != 4)
		return (0);
	x = 0;
	while (x < 4)
	{
		if (in[x] != '.' && in[x] != '#')
			return (0);
		x++;
	}
	return (1);
}

t_tetriminos	read_tetriminos(int fd, int *eof)
{
	t_tetriminos	tetriminos;
	char			*in;
	int				i;

	i = 0;
	while (i < 4)
	{
		in = zreadline(fd, eof);
		if (!tetriminos_input_ok(in))
		{
			free(in);
			tetriminos.valid = 0;
			return (tetriminos);
		}
		zmemcpy(&(tetriminos.data[i * 4]), in, 4);
		free(in);
		i++;
	}
	in = zreadline(fd, eof);
	tetriminos.valid = (zstrlen(in)) == 0 ? 1 : 0;
	return (tetriminos);
}

int				get_tetriminos(t_tetriminos *tetriminos, int fd, int *eof)
{
	*tetriminos = read_tetriminos(fd, eof);
	if (tetriminos->valid)
	{
		optimize_tetriminos(tetriminos);
		tetriminos->valid = verify_tetriminos_data(tetriminos->data);
	}
	return (tetriminos->valid);
}

int				load_tetriminos_list(t_tetriminos *tetriminos, int fd)
{
	int	eof;
	int	amount;

	amount = 0;
	eof = 0;
	while (eof == 0)
	{
		if (get_tetriminos(&(tetriminos[amount]), fd, &eof) == 0)
			return (-1);
		else
		{
			tetriminos[amount].id = 'A' + amount;
			amount++;
		}
	}
	return (amount);
}
