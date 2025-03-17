/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:11:02 by rodantec          #+#    #+#             */
/*   Updated: 2025/01/31 12:22:30 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			x = j * data->img_width;
			y = i * data->img_height;
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x,
					y);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
					x, y);
			j++;
		}
		i++;
	}
	return ;
}

void	render_map2(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			x = j * data->img_width;
			y = i * data->img_height;
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x,
					y);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img_fruit,
					x, y);
			j++;
		}
		i++;
	}
	return ;
}

void	render_map3(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			x = j * data->img_width;
			y = i * data->img_height;
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img_player,
					x, y);
			j++;
		}
		i++;
	}
	return ;
}

void	render_map_all(t_data *data)
{
	render_map(data);
	render_map2(data);
	render_map3(data);
}
