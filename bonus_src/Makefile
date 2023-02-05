# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:31:54 by mel-yous          #+#    #+#              #
#    Updated: 2023/02/02 15:43:39 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = animation_bonus.c drawer_bonus.c engine_bonus.c \
         helper_func_bonus.c map_checker_bonus.c map_reader_bonus.c \
		 mlx_func_bonus.c so_long_bonus.c solong_utils_bonus.c valid_path_bonus.c
OBJS = $(SRCS:.c=.o)

COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) \
	../libft/libft.a ../ft_printf/libftprintf.a \
	../get_next_line/libft_getnextline.a \
	-lmlx -framework OpenGL -framework AppKit

%.o: %.c so_long_bonus.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re