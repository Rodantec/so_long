/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:50:24 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/07 17:04:42 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_linelen(t_data *data)
{
	int		i;
	size_t	tmp;

	i = 1;
	tmp = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (tmp != ft_strlen(data->map[i]))
		{
			ft_printf("Error\nMap format issue");
			close_window(data);
		}
		i++;
	}
}

void	error_exit(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0 || k > 1)
	{
		if (k == 0)
			ft_printf("Error\nNo exit");
		else
			ft_printf("Error\nToo much exit");
		close_window(data);
	}
}

void	error_start(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j++])
		{
			if (data->map[i][j] == 'P')
				k++;
		}
		i++;
	}
	if (k == 0 || k > 1)
	{
		if (k == 0)
			ft_printf("Error\nNo players");
		else
			ft_printf("Error\nToo much players");
		close_window(data);
	}
}

int	error_conso(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k < 1)
	{
		ft_printf("Error\nNo consumable");
		close_window(data);
	}
	return (0);
}
