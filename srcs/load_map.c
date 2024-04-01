/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:11:49 by msumon            #+#    #+#             */
/*   Updated: 2023/11/30 13:56:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_height(char *str)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close (fd);
		free(line);
		print_error_and_exit("line failed");
	}
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

int	map_width(char *map_path)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = ft_strlen_sl(line) - 1;
	free(line);
	close(fd);
	return (width);
}

char	**load_map(char *map_path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		height;

	height = map_height(map_path);
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		print_error_and_exit("Error allocating memory for map");
	line = get_next_line(fd);
	while (i < height && line != NULL)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map[i] = NULL;
	return (map);
}
