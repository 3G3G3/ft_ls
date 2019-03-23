# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:40:34 by grgauthi          #+#    #+#              #
#    Updated: 2019/03/12 19:14:20 by grgauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putnbr.c		\
			ft_putendl.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstadd_fifo.c\
			ft_str2lst.c	\
			ft_split2lst.c	\
			ft_lstaddi.c	\
			ft_lstaddin.c	\
			ft_lstlen.c		\
			ft_putnbrendl.c	\
			ft_lstgetelem.c	\
			ft_putendllst.c	\
			ft_readfile.c	\
			ft_strchri.c	\
			ft_strjoinfree.c\
			ft_lstdelstr.c	\
			ft_lstiscs.c	\
			ft_lstiscs_del.c\
			ft_lstfindone.c	\
			ft_putlong.c	\
			ft_putllong.c	\
			ft_convert_base.c

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g3

NAME =  libft.a

.PHONY: clean fclean re

all :   $(NAME)

$(NAME) :   $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
