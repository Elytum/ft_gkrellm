# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/06/28 01:24:28 by bwanlin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = clang++
CFLAGS = -Wall -Wextra -Werror
#--------------Name-------------------------#
NAME = ft_gkrellm

#--------------Sources----------------------#
SRCS =	main.cpp					\
		graphic/ModuleRow.cpp		\
		graphic/MonitorModule.cpp	\
		graphic/Window.cpp			\
		modules/OSinfo.class.cpp	\
		modules/RAMModule.cpp		\
		modules/FooBar.cpp

INC = -I./graphic -I./modules

OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lncurses -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
