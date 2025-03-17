/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:56 by rodantec          #+#    #+#             */
/*   Updated: 2025/02/11 21:43:47 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	textures(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img_width, &data->img_height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "img/floor.xpm",
			&data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&data->img_width, &data->img_height);
	data->img_fruit = mlx_xpm_file_to_image(data->mlx, "img/fruits.xpm",
			&data->img_width, &data->img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "img/perso.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_exit || !data->img_wall || !data->img_floor
		|| !data->img_fruit || !data->img_player)
	{
		ft_printf("Error\nan image has not load");
		return (-1);
	}
	return (1);
}

void	free_textures(t_data *data)
{
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_fruit)
		mlx_destroy_image(data->mlx, data->img_fruit);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
}
