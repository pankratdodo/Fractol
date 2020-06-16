# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crycherd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 20:26:26 by crycherd          #+#    #+#              #
#    Updated: 2020/03/15 12:01:30 by plettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g3 -Ofast

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)/

LIBS		=	-lm -lpthread -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd

SRC_DIR		=	sources/
INC_DIR		=	includes/
OBJ_DIR		=	obj/

SRC_BASE	=	main.c init_main_struct.c key_hook.c mandelbar.c  heart.c burningship.c mandelbrot.c move.c juila.c bonus.c  threads.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) \
		$(FLAGS)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC)  -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)

clean:          cleanlib
	@rm -rf $(OBJ_DIR)

cleanlib:
	@make -C $(LIBFT_DIR) clean

cleansh:
	@rm -rf $(OBJ_DIR)

fclean:			fcleanlib cleansh
	@rm -f $(NAME)

fcleanlib:
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY :		fclean clean re cleanlib fcleanlib

-include $(OBJS:.o=.d)

