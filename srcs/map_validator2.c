/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:55:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/30 09:13:24 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	can_collect_all_and_exit(t_data *data, int x, int y, int *coins)
{
	if (x <= 0 || y <= 0 || y >= data->map_height || x >= data->map_width
		|| data->map[y][x] == '1' || data->map[y][x] == 'c'
		|| data->map[y][x] == 'o' || data->map[y][x] == 'e'
		|| data->map[y][x] == 'E')
	{
		if (data->map[y][x] == 'E')
		{
			data->map[y][x] = 'e';
			data->exitcheck = 1;
		}
		return ;
	}
	if (data->map[y][x] == 'C')
	{
		(*coins)--;
		data->map[y][x] = 'c';
	}
	else if (data->map[y][x] == '0')
		data->map[y][x] = 'o';
	can_collect_all_and_exit(data, x - 1, y, coins);
	can_collect_all_and_exit(data, x + 1, y, coins);
	can_collect_all_and_exit(data, x, y - 1, coins);
	can_collect_all_and_exit(data, x, y + 1, coins);
}

void	ft_restore(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'c')
				data->map[y][x] = 'C';
			else if (data->map[y][x] == 'e')
				data->map[y][x] = 'E';
			else if (data->map[y][x] == 'o')
				data->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

int	valid_path_check(t_data *data)
{
	int	x;
	int	y;
	int	coins;

	data->exitcheck = 0;
	coins = count_coins(data);
	get_current_position(data->map, &x, &y);
	can_collect_all_and_exit(data, x, y, &coins);
	if (coins != 0)
	{
		ft_printf("Error\n");
		ft_printf("No valid path, Access to coin is blocked\n");
		return (0);
	}
	ft_restore(data);
	if (data->exitcheck == 0)
	{
		ft_printf("Error\n");
		ft_printf("No valid path, Access to exit is blocked\n");
		return (0);
	}
	return (1);
}
