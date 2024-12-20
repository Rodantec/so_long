# Nom de l'exécutable
NAME = so_long

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Dossiers
SRC_DIR = .
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl
GAME_CONTROL_DIR = game_control
ERRORS_DIR = errors


SRC = $(SRC_DIR)/so_long.c \
      $(SRC_DIR)/textures.c \
      $(SRC_DIR)/map.c \
      $(SRC_DIR)/render_map.c \
      $(ERRORS_DIR)/errors_map.c
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.c \
            $(FT_PRINTF_DIR)/ft_iitoa.c \
            $(FT_PRINTF_DIR)/ft_hexamaj.c \
            $(FT_PRINTF_DIR)/ft_hexamin.c \
            $(FT_PRINTF_DIR)/ft_percent.c \
            $(FT_PRINTF_DIR)/ft_printchar.c \
            $(FT_PRINTF_DIR)/ft_printstr_fd.c \
            $(FT_PRINTF_DIR)/ft_size_n_deci.c \
            $(FT_PRINTF_DIR)/ft_size_n_hexa.c \
            $(FT_PRINTF_DIR)/ft_unsignedi.c \
            $(FT_PRINTF_DIR)/ft_voidpointer.c
GNL = $(GNL_DIR)/get_next_line.c \
      $(GNL_DIR)/get_next_line_utils.c
GAME_CONTROL = $(GAME_CONTROL_DIR)/player_move.c

# Tous les fichiers sources combinés
SRCS = $(SRC) $(FT_PRINTF) $(GNL) $(GAME_CONTROL)

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Flags pour la MiniLibX
MLX_FLAGS = -Imlx -Lmlx -lmlx -lXext -lX11 -lm -lz

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
