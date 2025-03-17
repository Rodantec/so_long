/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:27 by rodantec          #+#    #+#             */
/*   Updated: 2025/03/07 17:14:40 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_isnewline(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*line;
	char	*new_line;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_strdup("");
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		new_line = ft_strjoin(line, buffer);
		if (!new_line)
			return (free(buffer), free(line), NULL);
		free(line);
		line = new_line;
		if (ft_strchr(line, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(line), free(buffer), NULL);
	return (free(buffer), line);
}

char	*ft_extract(char **stash)
{
	int		i;
	char	*line;
	char	*new_stash;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + ((*stash)[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
	{
		line[i] = (*stash)[i];
		i++;
	}
	if ((*stash)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	new_stash = ft_strdup(*stash + i);
	if (!new_stash)
		return (NULL);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*gnl(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (!stash)
		stash = ft_strdup("");
	tmp = ft_isnewline(fd);
	if (!tmp)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_strjoin(stash, tmp);
	free(tmp);
	free(stash);
	stash = line;
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract(&stash);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gnl(fd);
	if (!line)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	char	*line2;
// 	char	*line3;
// 	char	*line4;
// 	char	*line5;
// 	char	*line6;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	line2 = get_next_line(fd);
// 	line3 = get_next_line(fd);
// 	line4 = get_next_line(fd);
// 	line5 = get_next_line(fd);
// 	line6 = get_next_line(fd);
// 	//  char *line7 = get_next_line(fd);
// 	//   char *line8 = get_next_line(fd);
// 	//    char *line9 = get_next_line(fd);
// 	//     char *line10 = get_next_line(fd);
// 	printf("%s", line);
// 	printf("%s", line2);
// 	//  printf("%s", line3);
// 	// printf("%s", line4);
// 	// printf(  "%s", line5);
// 	//  printf("%s", line6);
// 	free(line);
// 	free(line2);
// 	free(line3);
// 	free(line4);
// 	free(line5);
// 	free(line6);
// 	// printf("%s", line7);
// 	// printf("%s", line8);
// 	// printf("%s", line9);
// 	// printf("%s", line10);
// 	// N'oubliez pas de libérer la mémoire allouée pour la ligne
// 	close(fd);
// 	return (0);
// }
