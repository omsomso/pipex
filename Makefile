# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/03/08 19:38:34 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC_DIR	=	src/
CC 		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
LIBFT	=	$(SRC_DIR)libft/libft.a
RM		=	rm -f
SRC 	= 	$(SRC_DIR)main.c \
			$(SRC_DIR)pipex.c \
			$(SRC_DIR)pipex_utils.c
OBJ		=	$(SRC:.c=.o)
SRC_B 	= 	$(SRC_DIR)main_bonus.c \
			$(SRC_DIR)pipex_bonus.c \
			$(SRC_DIR)free_bonus.c \
			$(SRC_DIR)pipex_utils_bonus.c
OBJ_B	=	$(SRC_B:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(MAKE) -C $(SRC_DIR)libft
	@$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

bonus: $(SRC_B) $(OBJ_B)
	@$(MAKE) -C $(SRC_DIR)libft
	@$(CC) $(CFLAGS) -c $(SRC_B)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJ_B) $(LIBFT) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ) $(OBJ_B)
	@cd $(SRC_DIR)libft && $(MAKE) clean
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd $(SRC_DIR)libft && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"