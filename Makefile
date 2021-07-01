NAME = so_long

INCLUDES = includes


SRCS = get_file.c get_next_line.c main.c draw_rectangle.c print_error.c \


OBJS =${addprefix srcs/,${SRCS:.c=.o}}

CC = clang -g $(FLAGS)

LIBS = ./libft

FLAGS = -I. -I$(INCLUDES) -Wall -Werror -Wextra

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