NAME = so_long

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

LIBMLX = minilibx-linux/libmlx.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c \
	get_next_line.c \
	error.c \
	so_long_utils.c \
	list_utils.c \
	game_init.c \
	mlx_utils.c

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
		make -C ./printf
		make -C ./libft
		make -C ./minilibx-linux
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX) -lXext -lX11

all: $(NAME)

clean:
		make clean -C libft
		make clean -C printf
		make clean -C minilibx-linux
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft
		make fclean -C printf

re: fclean all 