NAME = ft_ls

SRC_PATH = ./srcs/
LIBFT_PATH = ./libft/
INC_PATH = ./includes/

CC = gcc
DEBUG_FLAGS = -g #-fsanitize=address
#DEBUG_FLAGS =  
CFLAGS = -Wall -Werror -Wextra -I $(INC_PATH) -I $(LIBFT_PATH) -g3

LIBFT = $(LIBFT_PATH)libft.a
SRCS = ft_longopt.c		\
		ft_getstats.c		\
		ft_tools.c			\
		ft_putlfldt.c		\
		ft_putdate.c		\
		ft_putsizes.c		\
		ft_puttools.c		\
		ft_free.c			\
		ft_lstsortedadd.c	\
		ft_parseopts.c		\
		ft_parsepath.c		\
		ft_exists.c			\
		ft_readtools.c		\
		ft_readlvl.c		\
		ft_read.c			\
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
