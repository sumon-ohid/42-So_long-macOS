/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:55:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:40:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangular(t_data *data)
{
	int		i;
	int		count;
	char	**map;

	map = data->map;
	i = 1;
	count = ft_strlen_sl(map[0]);
	while (map[i])
	{
		if (ft_strlen_sl(map[i]) != count)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_char(t_data *data)
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	**map;

	i = 0;
	height = data->map_height;
	width = data->map_width;
	map = data->map;
	while (map[i] && i < height)
	{
		j = 0;
		while (map[i][j] && j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_wall_around(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (i == 0 && data->map[i][j] != '1')
				return (0);
			else if (i == data->map_height - 1 && data->map[i][j] != '1')
				return (0);
			else
			{
				if (j == 0 && data->map[i][j] != '1')
					return (0);
				else if (j == data->map_width - 1 && data->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
