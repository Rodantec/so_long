/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:28:15 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/07 15:45:59 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->count = 0;
	data->fruit = 0;
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
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->fruit++;
			j++;
		}
		i++;
	}
	return (data->fruit);
}

int	player_move(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->p_x;
	new_y = data->p_y;
	if (keycode == 65307)
		close_window(data);
	calculate_new_position(keycode, &new_x, &new_y, data);
	if (can_move_to(new_x, new_y, data))
	{
		process_tile_content(new_x, new_y, data);
		update_map(new_x, new_y, data);
		render_map_all(data);
	}
	return (0);
}

void	calculate_new_position(int keycode, int *new_x, int *new_y,
		t_data *data)
{
	if ((keycode == 119 || keycode == 65362) && data->map[*new_y
			- 1][*new_x] != '1')
		*new_y = data->p_y - 1;
	else if ((keycode == 115 || keycode == 65364) && data->map[*new_y
			+ 1][*new_x] != '1')
		*new_y = data->p_y + 1;
	else if ((keycode == 97 || keycode == 65361) && data->map[*new_y][*new_x
		- 1] != '1')
		*new_x = data->p_x - 1;
	else if ((keycode == 100 || keycode == 65363) && data->map[*new_y][*new_x
		+ 1] != '1')
		*new_x = data->p_x + 1;
	if (*new_x != data->p_x || *new_y != data->p_y)
	{
		if (data->count == 2147483647)
		{
			ft_printf("Error\nToo much moves");
			close_window(data);
		}
		data->count++;
		ft_printf("%d\n", data->count);
	}
}

int	can_move_to(int new_x, int new_y, t_data *data)
{
	return (data->map[new_y][new_x] != '1');
}
