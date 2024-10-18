# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 16:50:58 by insoares          #+#    #+#              #
#    Updated: 2024/10/17 17:36:35 by insoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE	= -I include
CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
NAME = push_swap
PUSH_SWAP_FUNC = 	main.c ft_split_ps.c stack_init.c error_free_funcs.c error_free_funcs_2.c\
					sort_stack_funcs.c swap.c push.c rotate.c reverse_rotate.c simple_sort.c\
					radix.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_FUNC:.c=.o)


all:			$(NAME)

$(NAME):		$(LIBFT) $(PUSH_SWAP_OBJS) 
				$(CC) -o $@ $(PUSH_SWAP_OBJS) libft/libft.a

%.o:%.c
				$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
				make -C libft

clean:
				$(RM) $(PUSH_SWAP_OBJS)
				make -C libft clean

fclean: 		clean
				$(RM) $(NAME)
				make -C libft fclean

re: 			fclean all

visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	./bin/visualizer

.PHONY: all clean fclean re