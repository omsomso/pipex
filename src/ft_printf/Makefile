# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/01/25 19:16:16 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC 		=	gcc
FLAGS	=	-Wall -Werror -Wextra
LINK 	=	$(CC) $(FLAGS)
RM		=	rm -f
SRC 	= 	ft_printf.c \
			ft_printf_utils.c
AR 		=	ar -rcs
OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a libftprintf.a
	@$(CC) $(FLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ) $(OBJBNS)
	@cd libft && $(MAKE) clean 
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd libft && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"