# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/09 19:27:02 by bwanlin           #+#    #+#              #
#    Updated: 2015/06/28 02:11:58 by bwanlin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang++

CFLAGS	=	-Wall -Werror -Wextra -g

LDFLAGS	=

SRC		=	graphic/ModuleRow.cpp		\
			graphic/MonitorModule.cpp	\
			graphic/Window.cpp			\
			modules/Foobar.cpp			\
			modules/OSinfo.class.cpp	\
			modules/RAMModule.cpp

INC		=	includes

OBJ		=	$(SRC:.cpp=.o)

EXE		=	ex00

all		:	$(SRC) $(EXE)

$(EXE)	:	$(OBJ)
	$(CC) -o $(EXE) $(CFLAGS) $(OBJ) $(LDFLAGS)

%.o:%.cpp
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(EXE)

re		: fclean all
