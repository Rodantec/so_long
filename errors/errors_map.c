/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_data->map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:48 by rodantec          #+#    #+#             */
/*   Updated: 2024/12/12 17:30:01 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_linelen(t_data *data)
{
	int	i;
	size_t tmp;

	i = 1;
	tmp = strlen(data->map[0]);
	while (data->map[i])
	{
		if(tmp != strlen(data->map[i]))
		{
				ft_printf("Error\nWrongsize");
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
	if (k != 1)
	{
		ft_printf("Error\nExit problem");
        close_window(data);
	}
}
void	error_start(t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
    k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
	{
		ft_printf("Error\nstart problem");
        close_window(data);
	}
}
int	error_conso(t_data *data)
{
	int i;
	int j;
	int k;

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
		ft_printf("Error\nConso problem");
        close_window(data);
	}
	return (0);
}

void error_wall1(t_data *data)
{
    int i;
    
	i = 0;
	while (data->map[i])
	{
		if((data->map[i][0] != '1' ) || (data->map[i][data->map_width - 1] != '1'))
        {
            ft_printf("Error\nWall problem right and left");
            close_window(data);
        }
        i++;
    } 
}
void	error_wall2(t_data *data)
{
	int j;

	j = 0;

		while(data->map[0][j])
		{
			if((data->map[0][j] != '1' ) || (data->map[data->map_height - 1][j] != '1'))
        	{
           	 	ft_printf("Error\nWall problem up and down");
           		 close_window(data);
       		}
        	j++;
		}
}
void error_map(t_data *data)
{
	error_linelen(data);
    error_start(data);
    error_exit(data);
    error_conso(data);
    error_wall1(data);
	error_wall2(data);
}