# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 17:53:00 by uheirloo          #+#    #+#              #
#    Updated: 2019/09/10 18:44:33 by uheirloo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCCF = gcc -Wall -Wextra -Werror
SRC = ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  ft_strlen.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strrchr.c\
	  ft_tolower.c\
	  ft_toupper.c
HEAD = libft.h
OFILE = ft_isalnum.o\
	   	ft_isalpha.o\
	  	ft_isascii.o\
	 	ft_isdigit.o\
	  	ft_isprint.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_strcat.o\
		ft_strchr.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdup.o\
		ft_strlen.o\
		ft_strncat.o\
		ft_strncmp.o\
		ft_strncpy.o\
		ft_strrchr.o\
		ft_tolower.o\
		ft_toupper.o

all: $(NAME)

$(NAME): $(SRC)
	$(GCCF) -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

.PHONY: clean
clean:
	rm -f $(OFILE)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
