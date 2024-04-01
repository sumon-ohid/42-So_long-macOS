/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:56:21 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:40:21 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_current_position(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	map_width;
	int	map_height;

	map_height = height_count(map);
	map_width = ft_strlen_sl(map[0]);
	i = 0;
	while (i <= map_height)
	{
		j = 0;
		while (j <= map_width)
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	free_map(map);
}

int	count_coins(t_data *data)
{
	int		i;
	int		j;
	int		coins;
	char	**map;

	map = data->map;
	i = 0;
	coins = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

void	move_player(int new_x, int new_y, char **map, t_data *data)
{
	int	coins_collected;
	int	current_x;
	int	current_y;

	coins_collected = 0;
	get_current_position(map, &current_x, &current_y);
	data->total_coins = count_coins(data);
	if (map[new_y][new_x] != '1')
	{
		if (map[new_y][new_x] == 'E')
		{
			if (coins_collected == data->total_coins)
				quit_game(data);
			else
				return ;
		}
		if (map[new_y][new_x] == 'C')
			coins_collected++;
		map[current_y][current_x] = '0';
		map[new_y][new_x] = 'P';
		data->moves++;
	}
}

void	do_the_move(int keycode, t_data *data)
{
	int	x;
	int	y;

	get_current_position(data->map, &x, &y);
	if (keycode == KEY_W)
	{
		move_player(x, y - 1, data->map, data);
	}
	else if (keycode == KEY_A)
	{
		move_player(x - 1, y, data->map, data);
	}
	else if (keycode == KEY_S)
	{
		move_player(x, y + 1, data->map, data);
	}
	else if (keycode == KEY_D)
	{
		move_player(x + 1, y, data->map, data);
	}
	ft_printf("Moves: %d\n", data->moves);
	draw_elements(data);
	bonus_draw_text(data);
}
