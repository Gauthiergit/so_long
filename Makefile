NAME = so_long

DIR_OBJ = obj/

DIR_SRC = src/

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

LIBMLX = minilibx-linux/libmlx.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRCS = $(wildcard $(DIR_SRC)*.c)

OBJ = $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRCS))

$(NAME): $(OBJ)
		make -C ./printf
		make -C ./libft
		make -C ./minilibx-linux
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX) -lXext -lX11

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		make clean -C libft
		make clean -C printf
		make clean -C minilibx-linux
		rm -rf $(DIR_OBJ)

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft
		make fclean -C printf

re: fclean all 