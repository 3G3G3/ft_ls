NAME = ft_ls

SRC_PATH = ./srcs/
LIBFT_PATH = ./libft/
INC_PATH = ./includes/

CC = gcc
#DEBUG_FLAGS = -g  -fsanitize=address
DEBUG_FLAGS =  
CFLAGS = -Wall -Werror -Wextra -I $(INC_PATH) -I $(LIBFT_PATH) -g3

LIBFT = $(LIBFT_PATH)libft.a
SRCS = ft_putfldt.c			\
		ft_free.c			\
		ft_lstsortedadd.c	\
		ft_parseinput.c		\
		main.c

SRC = $(addprefix $(SRC_PATH), $(SRCS))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(DEBUG_FLAGS) -o $(NAME)  $(LIBFT) $(OBJ)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
