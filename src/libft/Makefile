# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 06:13:39 by kpawlows          #+#    #+#              #
#    Updated: 2023/03/02 02:42:28 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC_DIR	=	src/
CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
AR 		=	ar -rcs
RM		=	rm -rf
SRC 	= 	$(SRC_DIR)ft_atoi.c \
			$(SRC_DIR)ft_bzero.c \
			$(SRC_DIR)ft_calloc.c \
			$(SRC_DIR)ft_isalnum.c \
			$(SRC_DIR)ft_isalpha.c \
			$(SRC_DIR)ft_isascii.c \
			$(SRC_DIR)ft_isdigit.c \
			$(SRC_DIR)ft_isprint.c \
			$(SRC_DIR)ft_itoa.c \
			$(SRC_DIR)ft_memchr.c \
			$(SRC_DIR)ft_memcmp.c \
			$(SRC_DIR)ft_memcpy.c \
			$(SRC_DIR)ft_memmove.c \
			$(SRC_DIR)ft_memset.c \
			$(SRC_DIR)ft_putchar_fd.c \
			$(SRC_DIR)ft_putendl_fd.c \
			$(SRC_DIR)ft_putnbr_fd.c \
			$(SRC_DIR)ft_putstr_fd.c \
			$(SRC_DIR)ft_split.c \
			$(SRC_DIR)ft_strchr.c \
			$(SRC_DIR)ft_strrchr.c \
			$(SRC_DIR)ft_strdup.c \
			$(SRC_DIR)ft_striteri.c \
			$(SRC_DIR)ft_strjoin.c \
			$(SRC_DIR)ft_strlcat.c \
			$(SRC_DIR)ft_strlcpy.c \
			$(SRC_DIR)ft_strlen.c \
			$(SRC_DIR)ft_strmapi.c \
			$(SRC_DIR)ft_strncmp.c \
			$(SRC_DIR)ft_strnstr.c \
			$(SRC_DIR)ft_strtrim.c \
			$(SRC_DIR)ft_substr.c \
			$(SRC_DIR)ft_tolower.c \
			$(SRC_DIR)ft_toupper.c \
			$(SRC_DIR)get_next_line.c \
			$(SRC_DIR)get_next_line_utils.c \
			$(SRC_DIR)ft_printf.c \
			$(SRC_DIR)ft_printf_utils.c

OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@$(AR) $(NAME) $(OBJ)
	@printf "[libft]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ)
	@printf "[libft]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "[libft]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[libft]$(GREEN) \t re successful $(END)\n"