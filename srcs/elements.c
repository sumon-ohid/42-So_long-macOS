/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:58:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:40:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_game(t_data *data)
{
	draw_elements(data);
	bonus_draw_text(data);
	so_long_welcome();
}

void	element(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, x * CELL_SIZE, y
		* CELL_SIZE);
}

void	draw_elements(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				element(data, &data->wall_img, x, y);
			else if (data->map[y][x] == 'C')
				element(data, &data->coin_img, x, y);
			else if (data->map[y][x] == 'P')
				element(data, &data->player_img, x, y);
			else if (data->map[y][x] == 'E')
				element(data, &data->exit_img, x, y);
			else if (data->map[y][x] == '0')
				element(data, &data->bg_img, x, y);
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
