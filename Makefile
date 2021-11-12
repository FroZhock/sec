# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 16:44:13 by jmirmuln          #+#    #+#              #
#    Updated: 2021/10/30 16:44:21 by jmirmuln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_16base_large.c		ft_16base_small.c	ft_pointer.c\
			ft_putchar.c			ft_putnbr.c			ft_putstr.c\
			ft_unsigned_putnbr.c	ft_printf.c

HEADER	= 	ft_printf.h
OBJ		=	$(SRCS:%.c=%.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

