# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 18:43:27 by ydembele          #+#    #+#              #
#    Updated: 2025/07/10 12:51:00 by ydembele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR     = mlx
PRINTF_DIR  = printf
GNL_DIR     = get_next_line_malloc
INCLUDES    = -I$(MLX_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I/usr/include

SRCS =	main.c is_validber.c initialisation.c move.c playable.c free.c ft_split.c \
		ft_strjoin.c\
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c

# Objets
OBJS = $(SRCS:.c=.o)

# Librairies
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lbsd
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

# Règles
all: $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
