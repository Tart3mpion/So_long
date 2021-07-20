NAME = so_long

INCLUDES = includes


SRCS = get_file.c get_next_line.c main.c display.c print_error.c \
handle_keys.c exit_clean.c init_image.c movement.c init_text.c\


OBJS =${addprefix srcs/,${SRCS:.c=.o}}

CC = clang -g3 $(FLAGS)

LIBS = ./libft

FLAGS = -I. -I$(INCLUDES) -Wall -Werror -Wextra -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C $(LIBS)
	make -C mlx_linux
	$(CC) $(OBJS) -L$(LIBS) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean: clean
	rm $(NAME)

re : fclean all