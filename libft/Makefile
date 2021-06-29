NAME	= libft.a

SRCS	= ft_isalpha.c ft_memchr.c ft_strchr.c ft_strncmp.c \
ft_atoi.c ft_isascii.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
ft_calloc.c ft_isprint.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
ft_isalnum.c ft_memccpy.c ft_memset.c ft_strlen.c ft_toupper.c \
ft_strtrim.c ft_strjoin.c ft_substr.c ft_itoa.c ft_split.c ft_strmapi.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoli.c \

BONUSSRCS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lst_change_head.c\

OBJS	=	${SRCS:.c=.o}

BONUSOBJS	=	${BONUSSRCS:.c=.o}

CC	=	clang
RM	=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

bonus:	${BONUSOBJS} ${OBJS}		
	ar rcs ${NAME} ${OBJS} ${BONUSOBJS}

.PHONY:all clean fclean re bonus

