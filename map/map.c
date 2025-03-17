/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:59 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/10 13:42:14 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*width_of_map(char *string)
{
	char	*str;
	int		width;

	width = 0;
	str = malloc(ft_strlen(string) + 1);
	if (!str)
		return (NULL);
	if (string[0] == '\0')
		return (NULL);
	while (string[width] != '\0')
	{
		str[width] = string[width];
		width++;
	}
	if (string[width - 1] == '\n')
		str[width - 1] = '\0';
	str[width] = '\0';
	return (str);
}

void	free_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
}

int	close_window(t_data *data)
{
	free_textures(data);
	if (data->map)
		free_map(data);
	if (data->win)
		free_mlx(data);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(0);
	return (0);
}
