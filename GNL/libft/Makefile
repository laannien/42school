# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 15:54:23 by uheirloo          #+#    #+#              #
#    Updated: 2019/09/18 15:54:34 by uheirloo         ###   ########.fr        #
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
	  ft_bzero.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putendl.c\
	  ft_putnbr_fd.c\
	  ft_putnbr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_atoi.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strdel.c\
	  ft_strnew.c\
	  ft_strclr.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_strnlen.c\
	  ft_strlcat.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstpushback.c\
	  ft_bubblesort.c\
	  ft_strrev.c
OFILE = $(SRC:.c=.o)
HEAD = libft.h

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

so:
	$(GCCF) -fPIC -c $(SRC) -L $(HEAD)
	$(GCCF) -shared -o libft.so $(OFILE)

.PHONY: cleanso
cleanso: clean
	rm libft.so
