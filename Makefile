# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:13:34 by hthunder          #+#    #+#              #
#    Updated: 2019/11/18 14:12:09 by hthunder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
CC = gcc
DIR_S = srcs
DIR_O = temporary
INCLUDES = includes
SOURCES = printf.c \
		itoa.c \
		ft_itoabase.c \
		conversions.c \
		modifier.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p temporary
	$(CC) $(FLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(DIR_O)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

test: libftprintf.a main.c
	gcc -Wall -Wextra -Werror libftprintf.a main.c

tclean: fclean
	rm -f a.out