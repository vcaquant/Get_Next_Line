# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 03:44:14 by vcaquant          #+#    #+#              #
#    Updated: 2016/01/26 16:27:10 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = libft/ft_atoi.c \
		   libft/ft_strrchr.c \
		   libft/ft_bzero.c \
		   libft/ft_isalnum.c \
		   libft/ft_isalpha.c \
		   libft/ft_isascii.c \
		   libft/ft_isdigit.c \
		   libft/ft_isprint.c \
		   libft/ft_memccpy.c \
		   libft/ft_memchr.c \
		   libft/ft_memcmp.c \
		   libft/ft_memset.c \
		   libft/ft_memmove.c \
		   libft/ft_memcpy.c \
		   libft/ft_putchar.c \
		   libft/ft_putchar_fd.c \
		   libft/ft_putstr.c \
		   libft/ft_putstr_fd.c \
		   libft/ft_strcat.c \
		   libft/ft_strchr.c \
		   libft/ft_strcmp.c \
		   libft/ft_strcpy.c \
		   libft/ft_strdup.c \
		   libft/ft_strlcat.c \
		   libft/ft_strlen.c \
		   libft/ft_strncat.c \
		   libft/ft_strncmp.c \
		   libft/ft_strncpy.c \
		   libft/ft_strnstr.c \
		   libft/ft_strstr.c \
		   libft/ft_tolower.c \
		   libft/ft_toupper.c \
		   libft/ft_putendl.c \
		   libft/ft_putendl_fd.c \
		   libft/ft_putnbr.c \
		   libft/ft_putnbr_fd.c \
		   libft/ft_itoa.c \
		   libft/ft_memalloc.c \
		   libft/ft_memdel.c \
		   libft/ft_strclr.c \
		   libft/ft_strdel.c \
		   libft/ft_strequ.c \
		   libft/ft_striter.c \
		   libft/ft_striteri.c \
		   libft/ft_strjoin.c \
		   libft/ft_strmap.c \
		   libft/ft_strmapi.c \
		   libft/ft_strnequ.c \
		   libft/ft_strnew.c \
		   libft/ft_strsplit.c \
		   libft/ft_strsub.c \
		   libft/ft_strtrim.c \
		   libft/ft_strnncpy.c \
		   main.c \
		   get_next_line.c \

OBJ_PATH = ./

INC_PATH = ./

LIB_PATH = ./

NAME = gnl

CC = clang

CFLAGS = -Werror -Wall -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME):
		@echo "\033[032;32mCompilation Start\n"
		@echo "\033[032;33m"
	    $(CC) $(CFLAGS) $(SRC) -I $(INC) -o $(NAME)
		@echo "\033[032;32mCompilation Done :D\n"

exe: all
	./$(NAME)
	@echo "\033[032;33mFinish\n"

clean:
	/bin/rm -rf $(NAME)
	@echo "\033[032;31mFile Deleted ;)\n"

fclean: clean

re: clean fclean all

.PHONY : all clean fclean re
