# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 17:53:00 by uheirloo          #+#    #+#              #
#    Updated: 2019/09/13 13:36:17 by uheirloo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCCF = gcc -Wall -Wextra -Werror
SRC = ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_isspace.c\
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
	  ft_toupper.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_memchr.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memcmp.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_bzero.c
HEAD = libft.h
OFILE = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OFILE) $(HEAD)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

.c.o: 
	$(GCCF) -c $<

.PHONY: clean
clean:
	rm -f $(OFILE)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
