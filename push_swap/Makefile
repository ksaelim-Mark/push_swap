# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 14:05:13 by ksaelim           #+#    #+#              #
#    Updated: 2022/09/25 00:07:34 by ksaelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FT_UTILS =	get_stack.c \
		ft_utils.c

UTILS = $(addprefix utils/, $(FT_UTILS))

FT_STK = ft_sort.c \
	 check_sort.c \
	 swap.c \
	 push.c \
	 rotate.c \
	 re_rotate.c

STK = $(addprefix stack/, $(FT_STK))

SRCS = $(UTILS) $(STK) main.c
OBJS = $(SRCS:.c=.o)

LIB = ar -rcs
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $@ -g

$(OBJS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
