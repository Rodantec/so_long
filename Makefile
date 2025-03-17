# Nom de l'exécutable
NAME = so_long

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SOLONG = .
SRC_DIR = map
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl
GAME_CONTROL_DIR = game_control
ERRORS_DIR = errors
MLX_DIR = mlx

# Sources
SRC = $(SOLONG)/so_long.c \
      $(SRC_DIR)/textures.c \
      $(SRC_DIR)/map.c \
      $(SRC_DIR)/render_map.c \
      $(SRC_DIR)/loadmap.c \
      $(ERRORS_DIR)/errors_map.c \
      $(ERRORS_DIR)/errors_map2.c\
      $(ERRORS_DIR)/validmap.c
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
GAME_CONTROL = $(GAME_CONTROL_DIR)/player_move.c \
               $(GAME_CONTROL_DIR)/updatemap.c
SRCS = $(SRC) $(FT_PRINTF) $(GNL) $(GAME_CONTROL)

# Objets
OBJS = $(SRCS:.c=.o)

# Flags pour la bibliothèque mlx
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Cibles
all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

# Compilation de la bibliothèque mlx
$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all
