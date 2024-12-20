/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronate <ronate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:56 by rodantec          #+#    #+#             */
/*   Updated: 2024/12/20 11:59:15 by ronate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img_width, &data->img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "img/perso.xpm",
			&data->img_width, &data->img_height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "img/floor.xpm",
			&data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&data->img_width, &data->img_height);
	data->img_fruit = mlx_xpm_file_to_image(data->mlx, "img/fruits.xpm",
			&data->img_width, &data->img_height);
}
void free_textures(t_data *data)
{
    if (data->img_wall)
        mlx_destroy_image(data->mlx, data->img_wall);
    if (data->img_player)
        mlx_destroy_image(data->mlx, data->img_player);
    if (data->img_floor)
        mlx_destroy_image(data->mlx, data->img_floor);
    if (data->img_exit)
        mlx_destroy_image(data->mlx, data->img_exit);
    if (data->img_fruit)
        mlx_destroy_image(data->mlx, data->img_fruit);
}
