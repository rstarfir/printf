# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:13:34 by hthunder          #+#    #+#              #
#    Updated: 2019/11/14 17:19:50 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
LIBFT = libft
#CFLAGS = -Wall -Wextra
LFLAGS = -L$(LIBFT) -lft
CC = gcc 
SRCS = main.c \
		itoa.c \
		ft_itoabase.c \
		conversions.c \
		modifier.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = libft/includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
%.o: %.c
	$(CC) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
