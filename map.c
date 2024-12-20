#include "so_long.h"

static char *width_of_map(char *string)
{
	char *str;
    int width = 0;
	str = malloc(strlen(string) + 1);
	if (!str)
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
void free_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_window(t_data *data)
{
	int i;

	i = 0;
	free_textures(data);
	free_mlx(data);
	 if (data->map)
    {
       while(data->map[i])
        {
            free(data->map[i]);
			i++;
        }
        free(data->map);
		data->map = NULL;
    }
	free(data);
	exit(0);       
	return (0);                              
}

char	**load_map(const char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	char *tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	data->map = malloc(100 * sizeof(char *));
	if (!data->map)
		return NULL;
	while ((line = get_next_line(fd)))
	{
		tmp = width_of_map(line);
		data->map[i] = tmp;
		if (i == 0)
			data->map_width = strlen(tmp);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	line = NULL;
	close(fd);
	data->map_height = i;
	return (data->map);
}


