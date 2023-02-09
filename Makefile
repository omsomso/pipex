# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/02/09 12:59:39 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC_DIR	=	src/
CC 		=	gcc
FLAGS	=	
#-Werror -Wall -Wextra
LIBFTPF	=	$(SRC_DIR)ft_printf/libftprintf.a
LINK 	=	$(CC) $(FLAGS)
RM		=	rm -f
SRC 	= 	$(SRC_DIR)main.c \
			$(SRC_DIR)pipex.c \
			$(SRC_DIR)pipex_utils.c
OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C $(SRC_DIR)ft_printf
	@$(CC) $(FLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	
link : $(NAME) $(OBJ)
	@$(CC) $(OBJ) $(LIBFTPF) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ)
	@cd $(SRC_DIR)ft_printf && $(MAKE) clean
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd $(SRC_DIR)ft_printf && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"