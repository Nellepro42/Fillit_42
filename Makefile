#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/22 01:09:22 by ggambino          #+#    #+#              #
#    Updated: 2015/12/03 07:57:46 by ggambino         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBDIR			=	libzs
LIBBASE			=	array_basic base16_encoding bufferizer input_basic
LIBBASE			+=	memory_basic memory_copy output_basic
LIBBASE			+=	string_basic string_number string_plode string_advanced
LIB = $(addprefix $(LIBDIR)/,$(LIBBASE))

FULLBASE		=	$(LIB) examine_tetriminos solve_tetriminos
FULLBASE		+=	load_tetriminos start_tetriminos
FULLSRC			=	$(FULLBASE:=.c)
FULLOBJ			=	$(FULLBASE:=.o)

NAME            =   fillit

FLAG			=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(FULLOBJ)
		gcc $(FLAG) -o $(NAME) $(FULLOBJ)

%.o:			%.c
		gcc $(FLAG) -c -o $@ $^

re:		fclean all

clean:
		rm -f $(FULLOBJ)

fclean: clean
		rm -f $(NAME)
