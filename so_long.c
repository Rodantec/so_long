/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:53 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/10 13:42:34 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*init_data(char *map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	*data = (t_data){0};
	data->mlx = mlx_init();
	data->map = load_map(map_file, data);
	if (!data->map || data->map_height < 3 || data->map_width < 3)
	{
		if (data->map_width < 3 || data->map_height < 3)
			ft_printf("Error\nMissing something");
		close_window(data);
		return (NULL);
	}
	init_player(data);
	return (data);
}

void	setup_game(t_data *data)
{
	if (textures(data) == 1)
		error_map(data);
	else
		close_window(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (open_file(argv[1]) < 0)
		return (ft_printf("Error\nthis file does not exist"));
	if (argc != 2 || !errorfile(argv[1]))
		return (ft_printf("Error\nNot a .ber file"), 0);
	data = init_data(argv[1]);
	if (!data)
		return (0);
	data->win = NULL;
	setup_game(data);
	data->win = mlx_new_window(data->mlx, data->map_width * 64, data->map_height
			* 64, "so_long");
	render_map_all(data);
	mlx_key_hook(data->win, player_move, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	return (0);
}
