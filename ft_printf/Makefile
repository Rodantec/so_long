
SRCS = ft_printf.c \
       ft_iitoa.c \
       ft_hexamaj.c \
       ft_hexamin.c \
       ft_percent.c \
       ft_printchar.c \
       ft_printstr_fd.c \
       ft_size_n_deci.c \
       ft_size_n_hexa.c \
       ft_unsignedi.c \
       ft_voidpointer.c \

OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = libftprintf.a
LIBC    = ar rc
LIBR    = ranlib
CC        = gcc
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re