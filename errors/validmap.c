/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:02:55 by rodantec          #+#    #+#             */
/*   Updated: 2025/02/25 03:46:22 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_mapfloodfill(t_data *data)
{
	int	i;

	if (!data->mapfloodfill)
		return ;
	i = 0;
	while (i < data->map_height)
		free(data->mapfloodfill[i++]);
	free(data->mapfloodfill);
	data->mapfloodfill = NULL;
}

void	mapcopy(t_data *data)
{
	int	i;
	int	j;

	if (data->map_height < 3 || data->map_width < 3)
		return ;
	data->mapfloodfill = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->mapfloodfill)
		return ;
	i = 0;
	while (i < data->map_height)
	{
		data->mapfloodfill[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->mapfloodfill[i])
			return (free_mapfloodfill(data));
		j = 0;
		while (j < data->map_width)
		{
			data->mapfloodfill[i][j] = data->map[i][j];
			j++;
		}
		data->mapfloodfill[i][j] = '\0';
		i++;
	}
	data->mapfloodfill[i] = NULL;
}

void	flood_fil_alg(t_data *data, int y, int x)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return ;
	if (data->mapfloodfill[y][x] == '1' || data->mapfloodfill[y][x] == 'F')
		return ;
	data->mapfloodfill[y][x] = 'F';
	flood_fil_alg(data, y - 1, x);
	flood_fil_alg(data, y + 1, x);
	flood_fil_alg(data, y, x - 1);
	flood_fil_alg(data, y, x + 1);
}

int	verifmap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mapcopy(data);
	flood_fil_alg(data, data->p_y, data->p_x);
	while (i < data->map_height)
	{
		j = 0;
		while (j++ < data->map_width)
		{
			if (data->mapfloodfill[i][j] == 'E'
				|| data->mapfloodfill[i][j] == 'C'
				|| data->mapfloodfill[i][j] == 'P')
			{
				ft_printf("Error\nmap blocked");
				free_mapfloodfill(data);
				close_window(data);
				return (0);
			}
		}
		i++;
	}
	return (free_mapfloodfill(data), 1);
}

int	error_compo(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'C' && (data->map[i][j] != 'P')
				&& data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'E')
			{
				ft_printf("Error\nCompo problem");
				close_window(data);
			}
			j++;
		}
		i++;
	}
	return (0);
}
