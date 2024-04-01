# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2024/04/01 15:57:28 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ./srcs/so_long.c ./srcs/draw_game.c ./srcs/elements.c \
				./srcs/load_map.c ./srcs/key_moves.c ./srcs/so_long_utils.c \
				./srcs/map_validator.c ./srcs/map_validator1.c ./srcs/map_validator2.c
BONUS		= ./bonus/show_moves.c
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
LDFLAGS 	= -lmlx -framework OpenGL -framework AppKit
NAME		= so_long
LIBFT		= ./libft/
GNL			= ./libft/get_next_line/
FTPRINTF	= ./libft/ft_printf/
GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)

all: libft gnl ftprintf $(NAME)

libft:
	@echo ======== libft ========
	@$(MAKE) -C $(LIBFT) all

gnl:
	@echo ======== get_next_line ========
	@$(MAKE) -C $(GNL) all

ftprintf:
	@echo ======== ft_printf ========
	@$(MAKE) -C $(FTPRINTF) all

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT)libft.a $(GNL)gnl.a $(FTPRINTF)libftprintf.a $(LDFLAGS) -o $(NAME)
	@echo ${GREEN}======== So_long Compiled! ========

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@$(MAKE) -C $(GNL) clean
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@echo ======== Cleaned! ========
		
fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(GNL) fclean
	@rm -f $(NAME)
	@echo ======== Super Cleaned! ========
	
re: fclean all

.PHONY: all libft gnl ftprintf compile clean fclean re
.SILENT:
