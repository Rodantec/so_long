/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatemap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:25 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/10 13:34:00 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
