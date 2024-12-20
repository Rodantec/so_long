/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronate <ronate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:53 by rodantec          #+#    #+#             */
/*   Updated: 2024/12/20 16:55:28 by ronate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_data *data)
{
	data->map = load_map("maps/map1.ber", data);
	if(!data->map)
		close_window(data);
    error_map(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * 50,
			data->map_height * 50, "ooo");
	textures(data);
	init_player(data);
	render_map_all(data);
	mlx_key_hook(data->win, player_move, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	return (0);
}
int	main(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;

	int result = so_long(data);
	return (result);
}
