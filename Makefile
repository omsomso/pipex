# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/03/02 21:59:33 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC_DIR	=	src/
CC 		=	gcc
FLAGS	=	#-Werror -Wall -Wextra -g3
LIBFT	=	$(SRC_DIR)libft/libft.a
RM		=	rm -f
SRC 	= 	$(SRC_DIR)main.c \
			$(SRC_DIR)pipex.c \
			$(SRC_DIR)pipex_utils.c
OBJ		=	$(SRC:.c=.o)
SRCBNS 	= 	$(SRC_DIR)main_bonus.c \
			$(SRC_DIR)pipex_bonus.c \
			$(SRC_DIR)pipex_utils_bonus.c
OBJBNS		=	$(SRCBNS:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C $(SRC_DIR)libft
	@$(CC) $(FLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

bonus: $(SRCBNS)
	@$(MAKE) -C $(SRC_DIR)libft
	@$(CC) $(FLAGS) -c $(SRCBNS)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJBNS) $(LIBFT) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ) $(OBJBNS)
	@cd $(SRC_DIR)libft && $(MAKE) clean
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd $(SRC_DIR)libft && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"