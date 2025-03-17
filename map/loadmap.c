/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:23:19 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/10 13:41:58 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	save_map_line(t_data *data, char *line, int i)
{
	char	*tmp;

	tmp = width_of_map(line);
	if (!tmp)
		return ;
	data->map[i] = tmp;
	if (i == 0)
		data->map_width = ft_strlen(tmp);
}

int	load_map_lines(int fd, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		save_map_line(data, line, i);
		i++;
		free(line);
	}
	return (i);
}

int	countline(const char *filename)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open_file(filename);
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (i);
}

char	**load_map(const char *filename, t_data *data)
{
	int	fd;
	int	i;
	int	count;

	count = countline(filename);
	if (count > 2)
		data->map = malloc(count * sizeof(char *));
	else
		return (NULL);
	if (!data->map)
		return (NULL);
	fd = open_file(filename);
	if (fd < 0)
		return (NULL);
	i = load_map_lines(fd, data);
	if (i == -1)
		return (close(fd), free(data->map), NULL);
	data->map[i] = NULL;
	close(fd);
	data->map_height = i;
	return (data->map);
}
