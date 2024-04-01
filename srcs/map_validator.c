/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:12 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:40:36 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	contains_exit(t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = data->map;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	contains_collectible(t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = data->map;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		return (0);
	return (1);
}

int	contains_start(t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = data->map;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	is_valid_map(t_data *data)
{
	if (contains_exit(data) && contains_collectible(data)
		&& contains_start(data) && has_wall_around(data) && has_valid_char(data)
		&& valid_path_check(data) && is_rectangular(data))
		return (1);
	return (0);
}
