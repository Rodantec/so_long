#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img_exit;
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_fruit;
    int     fruit;
    int     p_x;
    int     p_y;
    int     img_width;
    int     img_height;
    int     map_width;
    int     map_height;
    int     count;
    char    **map;
}           t_data;


char    **load_map(const char *filename, t_data *data);
int	player_move(int keycode, t_data *data);
void textures(t_data *data);
void init_player(t_data *data);
int close_window(t_data *data);
void error_map(t_data *data);
void	calculate_new_position(int keycode, int *new_x, int *new_y, t_data *data);
int	can_move_to(int new_x, int new_y, t_data *data);
void	process_tile_content(int new_x, int new_y, t_data *data);
void	update_map(int new_x, int new_y, t_data *data);
void	render_game(t_data *data);
void render_map_all(t_data *data);
void   free_textures(t_data *data);
#endif
