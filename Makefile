# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:13:34 by hthunder          #+#    #+#              #
#    Updated: 2020/02/17 19:53:54 by hthunder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
CC = gcc -g
DIR_S = srcs
DIR_O = temporary
INCLUDES = -Iincludes
HEADER = includes/printf.h libft/includes/bigint.h libft/includes/custom_data_types.h libft/includes/libft.h
SOURCES = auxiliary.c \
        bonus_func.c \
        dragon4.c \
        ft_itoabase.c \
        ifbinary.c \
        ifchar.c \
        iffloat.c \
        handle_special_values.c \
        round_and_return_double.c \
        double_alignment_put_extra_symbs.c \
        ifhex.c \
        ifint.c \
        ifoctal.c \
        ifpointer.c \
        ifstring.c \
        ifudecint.c \
        modifier.c \
        printf.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	mkdir -p temporary
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(DIR_O)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
