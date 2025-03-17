/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:56 by rodantec          #+#    #+#             */
/*   Updated: 2025/02/25 03:38:27 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_wall1(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if ((data->map[i][0] != '1') || (data->map[i][data->map_width
				- 1] != '1'))
		{
			ft_printf("Error\nMap border issue, right or left");
			close_window(data);
		}
		i++;
	}
}

void	error_wall2(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
	{
		if ((data->map[0][j] != '1') || (data->map[data->map_height
				- 1][j] != '1'))
		{
			ft_printf("Error\nMap border issue, top or bottom");
			close_window(data);
		}
		j++;
	}
}

void	error_maxsize(t_data *data)
{
	if (data->map_width >= 60 || data->map_height >= 33)
	{
		ft_printf("Error\nMap too big");
		close_window(data);
	}
}

int	errorfile(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b' || str[i
			- 4] != '.')
		return (0);
	return (1);
}

void	error_map(t_data *data)
{
	error_compo(data);
	error_linelen(data);
	error_start(data);
	error_exit(data);
	error_conso(data);
	error_wall1(data);
	error_wall2(data);
	error_maxsize(data);
	verifmap(data);
}
