/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronate <ronate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:28:15 by rodantec          #+#    #+#             */
/*   Updated: 2024/12/20 15:12:04 by ronate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	countfruit(t_data *data)
{
	int	fruit;
	int	i;
	int	j;

	fruit = 0;
	i = 1;
	j = 1;
	while (data->map[i])
	{
		j = 1;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				fruit++;
			j++;
		}
		i++;
	}
	return (fruit);
}

int	player_move(int keycode, t_data *data)
{
	int	new_x = data->p_x;
	int	new_y = data->p_y;

	if (keycode == 65307)
		close_window(data);
	calculate_new_position(keycode, &new_x, &new_y, data);
	if (can_move_to(new_x, new_y, data))
	{
		process_tile_content(new_x, new_y, data);
		update_map(new_x, new_y, data);
		render_game(data);
	}
	return (0);
}
void	calculate_new_position(int keycode, int *new_x, int *new_y, t_data *data)
{
	if ((keycode == 119 || keycode == 65362) && data->map[*new_y - 1][*new_x] != '1')
	{
		*new_y = data->p_y - 1;
		data->count++;
		ft_printf("%d\n", data->count);
	}
	else if ((keycode == 115 || keycode == 65364) && data->map[*new_y + 1][*new_x] != '1')
	{
		*new_y = data->p_y + 1;
		data->count++;
		ft_printf("%d\n", data->count);
	}
	else if ((keycode == 97 || keycode == 65361) && data->map[*new_y][*new_x - 1] != '1')
	{
		*new_x = data->p_x - 1;
		data->count++;
		ft_printf("%d\n", data->count);
	}
	else if ((keycode == 100 || keycode == 65363) && data->map[*new_y][*new_x + 1] != '1')
	{
		*new_x = data->p_x + 1;
		data->count++;
		ft_printf("%d\n", data->count);
	}
}
int	can_move_to(int new_x, int new_y, t_data *data)
{
	return (data->map[new_y][new_x] != '1');
}
void	process_tile_content(int new_x, int new_y, t_data *data)
{
	if (data->map[new_y][new_x] == 'E' && data->fruit == countfruit(data))
		close_window(data);
	if (data->map[data->p_y][data->p_x] == 'C')
		data->fruit -= 1;
}
void	update_map(int new_x, int new_y, t_data *data)
{
	if (data->map[data->p_y][data->p_x] != 'E')
		data->map[data->p_y][data->p_x] = '0';
	data->p_x = new_x;
	data->p_y = new_y;
	if (data->map[new_y][new_x] != 'E')
		data->map[data->p_y][data->p_x] = 'P';
}
void	render_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	render_map_all(data);
}




